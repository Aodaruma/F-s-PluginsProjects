#include "FsG.h"
//***********************************************************************************
/*
	����
	xorShift�Ɋւ��Ă͈ȉ���HP�̋L�����Q�l�ɂ��܂����B

	������ɂԂ��`�����@2008�N10��31���@�����_��
	http://ogawa-sankinkoutai.seesaa.net/article/108848981.html

	����V���M�W�@Xorshift �̏�������
	http://d.hatena.ne.jp/gintenlabo/20100930/1285859540
*/
static A_u_long			FsRand_tbl[4];
//-------------------------------------------------------------------
void FsSrand(A_u_long s)
{
	A_u_long ss = s + 100;
	for (A_u_long i = 1; i <= 4; i++)
	{
		FsRand_tbl[i - 1] = ss = 1812433253U * (ss ^ (ss >> 30)) + i;
	}
}
//-------------------------------------------------------------------
A_u_long FsRand()
{
	A_u_long t = (FsRand_tbl[0] ^ (FsRand_tbl[0] << 11));
	FsRand_tbl[0] = FsRand_tbl[1];
	FsRand_tbl[1] = FsRand_tbl[2];
	FsRand_tbl[2] = FsRand_tbl[3];
	A_u_long ret = (FsRand_tbl[3] = (FsRand_tbl[3] ^ (FsRand_tbl[3] >> 19)) ^ (t ^ (t >> 8)));
	ret = (ret >> 16) & 0x7FFF;
	return ret;

}
//-------------------------------------------------------------------
double FsRandDouble()
{
	A_u_long t = (FsRand_tbl[0] ^ (FsRand_tbl[0] << 11));
	FsRand_tbl[0] = FsRand_tbl[1];
	FsRand_tbl[1] = FsRand_tbl[2];
	FsRand_tbl[2] = FsRand_tbl[3];
	A_u_long ret = (FsRand_tbl[3] = (FsRand_tbl[3] ^ (FsRand_tbl[3] >> 19)) ^ (t ^ (t >> 8)));
	ret = ret & 0x7FFFFFFF;

	return (double)ret / 0x7FFFFFFF;

}
