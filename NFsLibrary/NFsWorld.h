#pragma once
#ifndef NFsWorld_H
#define NFsWorld_H

#include "AE_SDK.h"
#include "NFsUtils.h"

class NFsWorld
{
protected:
	//アドレス計算テーブル・ポイントテーブル用
	PF_Handle	m_bufH = NULL;

	// アドレス計算テーブル
	A_long* m_vurTbl = NULL;


	A_long		m_width = 0;
	A_long		m_height = 0;
	A_long		m_widthTrue = 0;
	A_long		m_offsetWidth = 0;
	PF_PixelPtr m_data = NULL;
	PF_PixelFormat	m_format = PF_PixelFormat_ARGB32;

	PF_Pixel* m_data8 = NULL;
	PF_Pixel16* m_data16 = NULL;
	PF_PixelFloat* m_data32 = NULL;

public:
	PF_InData* in_data = NULL;
	PF_EffectWorld* world = NULL;

	A_long	width() { return m_width; }
	A_long	height() { return m_height; }
	A_long	widthTrue() { return  m_widthTrue; }
	A_long	offsetWidth() { m_offsetWidth; }
	PF_Pixel* data8() { return (PF_Pixel*)m_data; }
	PF_Pixel16* data16() { return (PF_Pixel16*)m_data; }
	PF_PixelFloat* data32() { return (PF_PixelFloat*)m_data; }
	PF_PixelFormat pixelFormat() { return m_format; }
	PF_FpLong downScale() {
		PF_FpLong ret = 1;
		if (in_data->downsample_x.den <= 0)
		{
			return ret;
		}
		ret = (double)in_data->downsample_x.num / (double)in_data->downsample_x.den;
		if (ret <= 0) ret = 1;
		return ret;
	}

	// ***************************************************************
#pragma region  Constractor
public:
	NFsWorld(
		PF_EffectWorld* wld = NULL,
		PF_InData* ind = NULL,
		PF_PixelFormat	fmt = PF_PixelFormat_ARGB32
	)
	{
		in_data = ind;
		world = wld;
		m_format = fmt;

		if (wld != NULL) {
			m_data = wld->data;
			m_width = wld->width;
			m_height = wld->height;

			switch (m_format)
			{
			case PF_PixelFormat_ARGB128:
				m_widthTrue = wld->rowbytes / sizeof(PF_Pixel32);
				m_data32 = (PF_PixelFloat*)m_data;
				break;
			case PF_PixelFormat_ARGB64:
				m_widthTrue = wld->rowbytes / sizeof(PF_Pixel16);
				m_data16 = (PF_Pixel16*)m_data;
				break;
			default:
			case PF_PixelFormat_ARGB32:
				m_widthTrue = wld->rowbytes / sizeof(PF_Pixel8);
				m_data8 = (PF_Pixel*)m_data;
				break;
			}
			m_offsetWidth = m_widthTrue - m_width;


			A_long bufLen = m_height * sizeof(A_long);
			bufLen *= 2;
			m_bufH = PF_NEW_HANDLE(bufLen);
			if (m_bufH) {
				m_vurTbl = *(A_long**)m_bufH;
				PF_LOCK_HANDLE(m_bufH);
				for (A_long i = 0; i < m_height; i++)
				{
					m_vurTbl[i] = i * m_widthTrue;
				}

			}
		}
	}
	// ***************************************************************
public:
	virtual ~NFsWorld()
	{
		if (in_data == NULL) return;
		if (m_bufH)
		{
			PF_UNLOCK_HANDLE(m_bufH);
			PF_DISPOSE_HANDLE(m_bufH);
			m_bufH = NULL;
		}
	}
#pragma endregion
	// ***************************************************************
#pragma region Pixel

	PF_Pixel GetPix8(A_long x, A_long y)
	{
		if (x < 0)x = 0; else if (x >= m_width) x = m_width - 1;
		if (y < 0)y = 0; else if (y >= m_height) y = m_height - 1;

		return m_data8[x + m_vurTbl[y]];

	}
	// ***************************************************************
	PF_Pixel16 GetPix16(A_long x, A_long y)
	{
		if (x < 0)x = 0; else if (x >= m_width) x = m_width - 1;
		if (y < 0)y = 0; else if (y >= m_height) y = m_height - 1;

		return m_data16[x + m_vurTbl[y]];

	}
	// ***************************************************************
	PF_PixelFloat GetPix32(A_long x, A_long y)
	{
		if (x < 0)x = 0; else if (x >= m_width) x = m_width - 1;
		if (y < 0)y = 0; else if (y >= m_height) y = m_height - 1;

		return m_data32[x + m_vurTbl[y]];

	}
	// ***************************************************************
	void SetPix8(A_long x, A_long y, PF_Pixel col)
	{
		if ((x < 0) || (x >= m_width)) return;
		if ((y < 0) || (y >= m_height)) return;

		m_data8[x + m_vurTbl[y]] = col;

	}
	// ***************************************************************
	void SetPix16(A_long x, A_long y, PF_Pixel16 col)
	{
		if ((x < 0) || (x >= m_width)) return;
		if ((y < 0) || (y >= m_height)) return;

		m_data16[x + m_vurTbl[y]] = col;

	}
	// ***************************************************************
	void SetPix32(A_long x, A_long y, PF_PixelFloat col)
	{
		if ((x < 0) || (x >= m_width)) return;
		if ((y < 0) || (y >= m_height)) return;

		m_data32[x + m_vurTbl[y]] = col;

	}
#pragma endregion

	// ***************************************************************
	public:
#pragma region PixelDouble
	PF_Pixel GetPixD8(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 -dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_Pixel a = GetPix8(ax, ay);
		PF_Pixel b = GetPix8(ax+1, ay);
		PF_Pixel c = GetPix8(ax, ay+1);
		PF_Pixel d = GetPix8(ax+1, ay + 1);

		PF_FpLong rd = (PF_FpLong)a.red * dx0 * dy0 + (PF_FpLong)b.red * dx1 * dy0 + (PF_FpLong)c.red * dx0 * dy1 + (PF_FpLong)d.red * dx1 * dy1;
		PF_FpLong gn = (PF_FpLong)a.green * dx0 * dy0 + (PF_FpLong)b.green * dx1 * dy0 + (PF_FpLong)c.green * dx0 * dy1 + (PF_FpLong)d.green * dx1 * dy1;
		PF_FpLong bu = (PF_FpLong)a.blue * dx0 * dy0 + (PF_FpLong)b.blue * dx1 * dy0 + (PF_FpLong)c.blue * dx0 * dy1 + (PF_FpLong)d.blue * dx1 * dy1;
		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_Pixel ret;
		ret.alpha = RoundByteDouble(al);
		ret.red = RoundByteDouble(rd);
		ret.green = RoundByteDouble(gn);
		ret.blue = RoundByteDouble(bu);

		return ret;

	}
	PF_Pixel16 GetPixD16(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 - dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_Pixel16 a = GetPix16(ax, ay);
		PF_Pixel16 b = GetPix16(ax + 1, ay);
		PF_Pixel16 c = GetPix16(ax, ay + 1);
		PF_Pixel16 d = GetPix16(ax + 1, ay + 1);

		PF_FpLong rd = (PF_FpLong)a.red * dx0 * dy0 + (PF_FpLong)b.red * dx1 * dy0 + (PF_FpLong)c.red * dx0 * dy1 + (PF_FpLong)d.red * dx1 * dy1;
		PF_FpLong gn = (PF_FpLong)a.green * dx0 * dy0 + (PF_FpLong)b.green * dx1 * dy0 + (PF_FpLong)c.green * dx0 * dy1 + (PF_FpLong)d.green * dx1 * dy1;
		PF_FpLong bu = (PF_FpLong)a.blue * dx0 * dy0 + (PF_FpLong)b.blue * dx1 * dy0 + (PF_FpLong)c.blue * dx0 * dy1 + (PF_FpLong)d.blue * dx1 * dy1;
		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_Pixel16 ret;
		ret.alpha = RoundShortFpLong(al);
		ret.red = RoundShortFpLong(rd);
		ret.green = RoundShortFpLong(gn);
		ret.blue = RoundShortFpLong(bu);

		return ret;

	}
	PF_PixelFloat GetPixD32(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 - dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_PixelFloat a = GetPix32(ax, ay);
		PF_PixelFloat b = GetPix32(ax + 1, ay);
		PF_PixelFloat c = GetPix32(ax, ay + 1);
		PF_PixelFloat d = GetPix32(ax + 1, ay + 1);

		PF_FpLong rd = (PF_FpLong)a.red * dx0 * dy0 + (PF_FpLong)b.red * dx1 * dy0 + (PF_FpLong)c.red * dx0 * dy1 + (PF_FpLong)d.red * dx1 * dy1;
		PF_FpLong gn = (PF_FpLong)a.green * dx0 * dy0 + (PF_FpLong)b.green * dx1 * dy0 + (PF_FpLong)c.green * dx0 * dy1 + (PF_FpLong)d.green * dx1 * dy1;
		PF_FpLong bu = (PF_FpLong)a.blue * dx0 * dy0 + (PF_FpLong)b.blue * dx1 * dy0 + (PF_FpLong)c.blue * dx0 * dy1 + (PF_FpLong)d.blue * dx1 * dy1;
		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_PixelFloat ret;
		ret.alpha = RoundFpShortDouble(al);
		ret.red = RoundFpShortDouble(rd);
		ret.green = RoundFpShortDouble(gn);
		ret.blue = RoundFpShortDouble(bu);

		return ret;

	}
	PF_Pixel GetPixDA8(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 - dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_Pixel a = GetPix8(ax, ay);
		PF_Pixel b = GetPix8(ax + 1, ay);
		PF_Pixel c = GetPix8(ax, ay + 1);
		PF_Pixel d = GetPix8(ax + 1, ay + 1);

		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_Pixel ret = { PF_MAX_CHAN8,PF_MAX_CHAN8,PF_MAX_CHAN8,PF_MAX_CHAN8 };
		ret.alpha = RoundByteDouble(al);

		return ret;

	}
	PF_Pixel16 GetPixDA16(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 - dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_Pixel16 a = GetPix16(ax, ay);
		PF_Pixel16 b = GetPix16(ax + 1, ay);
		PF_Pixel16 c = GetPix16(ax, ay + 1);
		PF_Pixel16 d = GetPix16(ax + 1, ay + 1);

		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_Pixel16 ret = { PF_MAX_CHAN16,PF_MAX_CHAN16,PF_MAX_CHAN16,PF_MAX_CHAN16 };
		ret.alpha = RoundShortFpLong(al);

		return ret;

	}
	PF_PixelFloat GetPixDA32(PF_FpLong x, PF_FpLong y)
	{
		A_long ax = (A_long)x;
		A_long ay = (A_long)y;

		PF_FpLong dx1 = x - (PF_FpLong)ax;
		PF_FpLong dy1 = y - (PF_FpLong)ay;
		PF_FpLong dx0 = 1 - dx1;
		PF_FpLong dy0 = 1 - dy1;

		PF_PixelFloat a = GetPix32(ax, ay);
		PF_PixelFloat b = GetPix32(ax + 1, ay);
		PF_PixelFloat c = GetPix32(ax, ay + 1);
		PF_PixelFloat d = GetPix32(ax + 1, ay + 1);

		PF_FpLong al = (PF_FpLong)a.alpha * dx0 * dy0 + (PF_FpLong)b.alpha * dx1 * dy0 + (PF_FpLong)c.alpha * dx0 * dy1 + (PF_FpLong)d.alpha * dx1 * dy1;

		PF_PixelFloat ret = { 1,1,1,1 };
		ret.alpha = RoundFpShortDouble(al);

		return ret;

	}
#pragma endregion
	protected:
	// ***************************************************************
#pragma region Copy
	// ***************************************************************
	PF_Err Copy8(NFsWorld *d)
	{
		PF_Err err = PF_Err_NONE;

		if ((m_data == NULL) || (d->m_data == NULL)) return PF_Err_OUT_OF_MEMORY;
		if ((m_width != d->m_width) || (m_height != d->m_height)) return PF_Err_OUT_OF_MEMORY;
		if (m_format != d->m_format) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				m_data8[target] = d->m_data8[targetD];
				target++;
				targetD++;
			}
			target += m_offsetWidth;
			targetD += d->m_offsetWidth;
		}
		return err;
	}
	// ***************************************************************
	PF_Err Copy16(NFsWorld *d)
	{
		PF_Err err = PF_Err_NONE;

		if ((m_data == NULL) || (d->m_data == NULL)) return PF_Err_OUT_OF_MEMORY;
		if ((m_width != d->m_width) || (m_height != d->m_height)) return PF_Err_OUT_OF_MEMORY;
		if (m_format != d->m_format) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				m_data16[target] = d->m_data16[targetD];
				target++;
				targetD++;
			}
			target += m_offsetWidth;
			targetD += d->m_offsetWidth;
		}
		return err;
	}
	// ***************************************************************
	PF_Err Copy32(NFsWorld *d)
	{
		PF_Err err = PF_Err_NONE;

		if ((m_data == NULL) || (d->m_data == NULL)) return PF_Err_OUT_OF_MEMORY;
		if ((m_width != d->m_width) || (m_height != d->m_height)) return PF_Err_OUT_OF_MEMORY;
		if (m_format != d->m_format) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				m_data32[target] = d->m_data32[targetD];
				target++;
				targetD++;
			}
			target += m_offsetWidth;
			targetD += d->m_offsetWidth;
		}
		return err;
	}

#pragma endregion
	// ***************************************************************
#pragma region SelectedPixel
	// ***************************************************************
	PF_Err SelectedPixel8(PF_Pixel* cols, A_long cnt, A_u_char lv)
	{
		PF_Err err = PF_Err_NONE;
		PF_Pixel empcol = { 0,0,0,0 };
		if (m_data == NULL) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel s = m_data8[target];
				A_long idx = -1;
				for (A_long j = 0; j < cnt; j++)
				{
					if (compPix8Lv(s, cols[j], lv) == TRUE)
					{
						idx = j;
						break;
					}
				}
				if (idx == -1) m_data8[target] = empcol;
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	// ***************************************************************
	PF_Err SelectedPixel16(PF_Pixel* cols, A_long cnt, A_u_char lv)
	{
		PF_Err err = PF_Err_NONE;
		PF_Pixel16 empcol = { 0,0,0,0 };
		if (m_data == NULL) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel16 s = m_data16[target];
				A_long idx = -1;
				for (A_long j = 0; j < cnt; j++)
				{
					if (compPix16_8Lv(s, cols[j], lv) == TRUE)
					{
						idx = j;
						break;
					}
				}
				if (idx == -1) m_data16[target] = empcol;
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	// ***************************************************************
	PF_Err SelectedPixel32(PF_Pixel* cols, A_long cnt, A_u_char lv)
	{
		PF_Err err = PF_Err_NONE;
		PF_PixelFloat empcol = { 0,0,0,0 };
		if (m_data == NULL) return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_PixelFloat s = m_data32[target];
				A_long idx = -1;
				for (A_long j = 0; j < cnt; j++)
				{
					if (compPix32_8Lv(s, cols[j], lv) == TRUE)
					{
						idx = j;
						break;
					}
				}
				if (idx == -1) m_data32[target] = empcol;
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
#pragma endregion
	// ***************************************************************
#pragma region Mat
	PF_Err ToMat8()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		PF_Pixel emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel s = m_data8[target];
				if (s.alpha == 0)
				{
					m_data8[target] = emp;
				}
				else if (s.alpha < PF_MAX_CHAN8)
				{
					PF_FpLong a = (PF_FpLong)s.alpha / PF_MAX_CHAN8;
					s.red = RoundByteFpLong((PF_FpLong)s.red * a);
					s.green = RoundByteFpLong((PF_FpLong)s.green * a);
					s.blue = RoundByteFpLong((PF_FpLong)s.blue * a);
					m_data8[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	PF_Err FromMat8()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		PF_Pixel emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel s = m_data8[target];
				if (s.alpha == 0)
				{
					m_data8[target] = emp;
				}
				else if (s.alpha < PF_MAX_CHAN8)
				{
					PF_FpLong a = (PF_FpLong)s.alpha / PF_MAX_CHAN8;
					s.red = RoundByteFpLong((PF_FpLong)s.red / a);
					s.green = RoundByteFpLong((PF_FpLong)s.green / a);
					s.blue = RoundByteFpLong((PF_FpLong)s.blue / a);
					m_data8[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	PF_Err ToMat16()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		PF_Pixel16 emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel16 s = m_data16[target];
				if (s.alpha == 0)
				{
					m_data16[target] = emp;
				}
				else if (s.alpha < PF_MAX_CHAN16)
				{
					PF_FpLong a = (PF_FpLong)s.alpha / PF_MAX_CHAN16;
					s.red = RoundShortFpLong((PF_FpLong)s.red * a);
					s.green = RoundShortFpLong((PF_FpLong)s.green * a);
					s.blue = RoundShortFpLong((PF_FpLong)s.blue * a);
					m_data16[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	PF_Err FromMat16()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		PF_Pixel16 emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_Pixel16 s = m_data16[target];
				if (s.alpha == 0)
				{
					m_data16[target] = emp;
				}
				else if (s.alpha < PF_MAX_CHAN16)
				{
					PF_FpLong a = (PF_FpLong)s.alpha / PF_MAX_CHAN16;
					s.red = RoundShortFpLong((PF_FpLong)s.red / a);
					s.green = RoundShortFpLong((PF_FpLong)s.green / a);
					s.blue = RoundShortFpLong((PF_FpLong)s.blue / a);
					m_data16[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	PF_Err ToMat32()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		PF_PixelFloat emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_PixelFloat s = m_data32[target];
				if (s.alpha == 0)
				{
					m_data32[target] = emp;
				}
				else if (s.alpha < 1)
				{
					PF_FpLong a = (PF_FpLong)s.alpha;
					s.red = RoundFpShortDouble((PF_FpLong)s.red * a);
					s.green = RoundFpShortDouble((PF_FpLong)s.green * a);
					s.blue = RoundFpShortDouble((PF_FpLong)s.blue * a);
					m_data32[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
	PF_Err FromMat32()
	{
		PF_Err err = PF_Err_NONE;

		if (m_data == NULL)  return PF_Err_OUT_OF_MEMORY;

		A_long target = 0;
		A_long targetD = 0;
		PF_PixelFloat emp = { 0,0,0,0 };

		for (A_long y = 0; y < m_height; y++)
		{
			for (A_long x = 0; x < m_width; x++)
			{
				PF_PixelFloat s = m_data32[target];
				if (s.alpha == 0)
				{
					m_data32[target] = emp;
				}
				else if (s.alpha < 1)
				{
					PF_FpLong a = (PF_FpLong)s.alpha;
					s.red = RoundFpShortDouble((PF_FpLong)s.red / a);
					s.green = RoundFpShortDouble((PF_FpLong)s.green / a);
					s.blue = RoundFpShortDouble((PF_FpLong)s.blue / a);
					m_data32[target] = s;
				}
				target++;
			}
			target += m_offsetWidth;
		}
		return err;
	}
#pragma endregion
	// ***************************************************************
public:
	PF_Err Copy(NFsWorld *d)
	{
		PF_Err err = PF_Err_NONE;
		switch (m_format)
		{
		case PF_PixelFormat_ARGB128:
			err = Copy32(d);
			break;
		case PF_PixelFormat_ARGB64:
			err = Copy16(d);
			break;
		case PF_PixelFormat_ARGB32:
			err = Copy8(d);
			break;
		}
		return err;
	}
	PF_Err SelectedPixel(PF_Pixel* cols, A_long cnt, A_u_char lv)
	{
		PF_Err err = PF_Err_NONE;
		switch (m_format)
		{
		case PF_PixelFormat_ARGB128:
			err = SelectedPixel32(cols, cnt, lv);
			break;
		case PF_PixelFormat_ARGB64:
			err = SelectedPixel16(cols, cnt, lv);
			break;
		case PF_PixelFormat_ARGB32:
			err = SelectedPixel8(cols,cnt,lv);
			break;
		}
		return err;
	}
	PF_Err ToMat()
	{
		PF_Err err = PF_Err_NONE;
		switch (m_format)
		{
		case PF_PixelFormat_ARGB128:
			err = ToMat32();
			break;
		case PF_PixelFormat_ARGB64:
			err = ToMat16();
			break;
		case PF_PixelFormat_ARGB32:
			err = ToMat8();
			break;
		}
		return err;
	}
	PF_Err FromMat()
	{
		PF_Err err = PF_Err_NONE;
		switch (m_format)
		{
		case PF_PixelFormat_ARGB128:
			err = FromMat32();
			break;
		case PF_PixelFormat_ARGB64:
			err = FromMat16();
			break;
		case PF_PixelFormat_ARGB32:
			err = FromMat8();
			break;
		}
		return err;
	}
	PF_Pixel GetPixelValue8(A_long x, A_long y)
	{
		PF_Pixel ret = { 0,0,0,0 };
		switch (m_format)
		{
		case PF_PixelFormat_ARGB128:
			ret = CONV32TO8(GetPix32(x, y));
			break;
		case PF_PixelFormat_ARGB64:
			ret = CONV16TO8( GetPix16(x, y));
			break;
		case PF_PixelFormat_ARGB32:
			ret = GetPix8(x, y);
			break;
		}
		return ret;
	}
#pragma region Iterate


	// ******************************************************************
	PF_Err Iterate8(
		void* refcon,
		PF_Err(*pix_fn)(void* refcon, A_long x, A_long y, PF_Pixel* p)
	)
	{
		PF_Err	err = PF_Err_NONE;
		PF_Pixel* d = data8();

		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				pix_fn(refcon,
					x,
					y,
					d
				);
				d++;
			}
			d += m_offsetWidth;
		}

		return err;
	}
	// ******************************************************************
	PF_Err Iterate16(
		void* refcon,
		PF_Err(*pix_fn)(void* refcon, A_long x, A_long y, PF_Pixel16* p)
	)
	{
		PF_Err	err = PF_Err_NONE;
		PF_Pixel16* d = data16();

		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				pix_fn(refcon,
					x,
					y,
					d
				);
				d++;
			}
			d += m_offsetWidth;
		}

		return err;
	}
	// ******************************************************************
	PF_Err Iterate32(
		void* refcon,
		PF_Err(*pix_fn)(void* refcon, A_long x, A_long y, PF_PixelFloat* p)
	)
	{
		PF_Err	err = PF_Err_NONE;
		PF_PixelFloat* d = data32();

		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				pix_fn(refcon,
					x,
					y,
					d
				);
				d++;
			}
			d += m_offsetWidth;
		}

		return err;
	}
#pragma endregion
	// ******************************************************************

};
#endif