//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------


#include "Spark.h"


//-------------------------------------------------------------------------------------------------
//AfterEffexts�Ƀp�����[�^��ʒB����
//Param_Utils.h���Q�Ƃ̂���
static PF_Err ParamsSetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output)
{
	PF_Err			err = PF_Err_NONE;
	PF_ParamDef		def;

	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_SEED,	//�p�����[�^�̖��O
		-30000, 				//���l���͂���ꍇ�̍ŏ��l
		30000,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		1000,			//�X���C�_�[�̍ő�l
		0,				//�f�t�H���g�̒l
		ID_SEED
	);
	//----------------------------------------------------------------
//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_OFFSET, 0, ID_OFFSET);
	//----------------------------------------------------------------
	//�ʒu�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_POINT(STR_START,			/*"New Center"*/
		25,	// X
		25,	// Y
		0,	// Flag
		ID_START
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_STARTRANDX,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		500,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		100,				//�X���C�_�[�̍ő�l
		10,				//�f�t�H���g�̒l
		ID_STARTRANDX
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_STARTRANDY,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		500,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		100,				//�X���C�_�[�̍ő�l
		10,				//�f�t�H���g�̒l
		ID_STARTRANDY
	);
	//----------------------------------------------------------------
	//�ʒu�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_POINT(STR_LAST,			/*"New Center"*/
		75,	// X
		75,	// Y
		0,	// Flag
		ID_LAST
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_LASTRANDX,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		500,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		100,				//�X���C�_�[�̍ő�l
		10,				//�f�t�H���g�̒l
		ID_LASTRANDX
	);	
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_LASTRANDY,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		500,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		100,				//�X���C�_�[�̍ő�l
		10,				//�f�t�H���g�̒l
		ID_LASTRANDY
	);

	
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINESIZE,	//Name
		0,						//VALID_MIN
		300,						//VALID_MAX
		0,						//SLIDER_MIN
		100,						//SLIDER_MAX
		1,						//CURVE_TOLERANCE
		25,						//DFLT
		1,						//PREC
		0,						//DISP
		0,						//WANT_PHASE
		ID_LINESIZE
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_LINEMOVE,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		2000,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		100,				//�X���C�_�[�̍ő�l
		50,				//�f�t�H���g�̒l
		ID_LINEMOVE
	);	
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_SUBCOUNT,	//�p�����[�^�̖��O
		0, 				//���l���͂���ꍇ�̍ŏ��l
		20,			//���l���͂���ꍇ�̍ő�l
		0,				//�X���C�_�[�̍ŏ��l 
		10,				//�X���C�_�[�̍ő�l
		2,				//�f�t�H���g�̒l
		ID_SUB_COUNT
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_FOLDCOUNT,	//�p�����[�^�̖��O
		1, 				//���l���͂���ꍇ�̍ŏ��l
		10,			//���l���͂���ꍇ�̍ő�l
		1,				//�X���C�_�[�̍ŏ��l 
		5,				//�X���C�_�[�̍ő�l
		3,				//�f�t�H���g�̒l
		ID_FOLD_COUNT
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(STR_DRAWCOUNT,	//�p�����[�^�̖��O
		1, 				//���l���͂���ꍇ�̍ŏ��l
		50,			//���l���͂���ꍇ�̍ő�l
		1,				//�X���C�_�[�̍ŏ��l 
		5,				//�X���C�_�[�̍ő�l
		2,				//�f�t�H���g�̒l
		ID_DRAW_COUNT
	);

	//----------------------------------------------------------------
//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(STR_COLOR,
		0xFF,
		0xFF,
		0xFF,
		ID_COLOR
	);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_BLEND,
		STR_ON,
		FALSE,
		0,
		ID_BLEND
	);
	//----------------------------------------------------------------
	out_data->num_params = 	ID_NUM_PARAMS; 

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err
HandleChangedParam(
	PF_InData					*in_data,
	PF_OutData					*out_data,
	PF_ParamDef					*params[],
	PF_LayerDef					*outputP,
	PF_UserChangedParamExtra	*extraP)
{
	PF_Err				err = PF_Err_NONE;
	return err;
}
//-----------------------------------------------------------------------------------
static PF_Err
QueryDynamicFlags(	
	PF_InData		*in_data,	
	PF_OutData		*out_data,	
	PF_ParamDef		*params[],	
	void			*extra)	
{
	PF_Err 	err = PF_Err_NONE;
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err
FilterImage8(
	refconType	refcon,
	A_long		xL,
	A_long		yL,
	PF_Pixel* inP,
	PF_Pixel* outP)
{
	PF_Err			err = PF_Err_NONE;

	A_u_char v = outP->alpha;

	if (v <= 0) {
		*outP = *inP;
	}
	else {
		PF_FpLong v0 = (PF_FpLong)inP->alpha / PF_MAX_CHAN8;
		PF_FpLong r0 = (PF_FpLong)inP->red * v0;
		PF_FpLong g0 = (PF_FpLong)inP->green * v0;
		PF_FpLong b0 = (PF_FpLong)inP->blue * v0;

		PF_FpLong v1 = (PF_FpLong)outP->alpha / PF_MAX_CHAN8;
		PF_FpLong r1 = (PF_FpLong)outP->red * v1;
		PF_FpLong g1 = (PF_FpLong)outP->green * v1;
		PF_FpLong b1 = (PF_FpLong)outP->blue * v1;

		r1 = r0 * (1 - v1) + r1 * v1;
		g1 = g0 * (1 - v1) + g1 * v1;
		b1 = b0 * (1 - v1) + b1 * v1;

		v1 = v0 + v1 - v0 * v1;

		r1 /= v1;
		g1 /= v1;
		b1 /= v1;

		outP->alpha = RoundByteFpLong(v1*PF_MAX_CHAN8);
		outP->red = RoundByteFpLong(r1);
		outP->green = RoundByteFpLong(g1);
		outP->blue = RoundByteFpLong(b1);

	}

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err
FilterImage16(
	refconType	refcon,
	A_long		xL,
	A_long		yL,
	PF_Pixel16* inP,
	PF_Pixel16* outP)
{
	PF_Err			err = PF_Err_NONE;

	A_u_short v = outP->alpha;

	if (v <= 0) {
		*outP = *inP;
	}
	else {
		PF_FpLong v0 = (PF_FpLong)inP->alpha / PF_MAX_CHAN16;
		PF_FpLong r0 = (PF_FpLong)inP->red * v0;
		PF_FpLong g0 = (PF_FpLong)inP->green * v0;
		PF_FpLong b0 = (PF_FpLong)inP->blue * v0;

		PF_FpLong v1 = (PF_FpLong)outP->alpha / PF_MAX_CHAN16;
		PF_FpLong r1 = (PF_FpLong)outP->red * v1;
		PF_FpLong g1 = (PF_FpLong)outP->green * v1;
		PF_FpLong b1 = (PF_FpLong)outP->blue * v1;

		r1 = r0 * (1 - v1) + r1 * v1;
		g1 = g0 * (1 - v1) + g1 * v1;
		b1 = b0 * (1 - v1) + b1 * v1;

		v1 = v0 + v1 - v0 * v1;

		r1 /= v1;
		g1 /= v1;
		b1 /= v1;

		outP->alpha = RoundShortFpLong(v1 * PF_MAX_CHAN16);
		outP->red = RoundShortFpLong(r1);
		outP->green = RoundShortFpLong(g1);
		outP->blue = RoundShortFpLong(b1);

	}

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err
FilterImage32(
	refconType	refcon,
	A_long		xL,
	A_long		yL,
	PF_PixelFloat* inP,
	PF_PixelFloat* outP)
{
	PF_Err			err = PF_Err_NONE;

	PF_FpShort v = outP->alpha;

	if (v <= 0) {
		*outP = *inP;
	}
	else {
		PF_FpLong v0 = (PF_FpLong)inP->alpha;
		if (v0 > 1) v0 = 1;
		PF_FpLong r0 = (PF_FpLong)inP->red * v0;
		PF_FpLong g0 = (PF_FpLong)inP->green * v0;
		PF_FpLong b0 = (PF_FpLong)inP->blue * v0;

		PF_FpLong v1 = (PF_FpLong)outP->alpha;
		if (v1 > 1) v1 = 1;
		PF_FpLong r1 = (PF_FpLong)outP->red * v1;
		PF_FpLong g1 = (PF_FpLong)outP->green * v1;
		PF_FpLong b1 = (PF_FpLong)outP->blue * v1;

		r1 = r0 * (1 - v1) + r1 * v1;
		g1 = g0 * (1 - v1) + g1 * v1;
		b1 = b0 * (1 - v1) + b1 * v1;

		v1 = v0 + v1 - v0 * v1;

		r1 /= v1;
		g1 /= v1;
		b1 /= v1;

		outP->alpha = RoundShortFpLong(v1);
		outP->red = RoundShortFpLong(r1);
		outP->green = RoundShortFpLong(g1);
		outP->blue = RoundShortFpLong(b1);

	}

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;

	infoP->start.s = 0;
	infoP->start.s = 0;

	PF_FixedPoint v;
	ERR(ae->GetFIXEDPOINT(ID_START, &v));
	if (!err) {
		infoP->start.p.x = (int)((double)v.x / 65536 + 0.5);
		infoP->start.p.y = (int)((double)v.y / 65536 + 0.5);
	}
	ERR(ae->GetADD(ID_STARTRANDX, &infoP->startRandX));
	ERR(ae->GetADD(ID_STARTRANDY, &infoP->startRandY));

	ERR(ae->GetFIXEDPOINT(ID_LAST, &v));
	if (!err) {
		infoP->last.p.x = (int)((double)v.x / 65536 + 0.5);
		infoP->last.p.y = (int)((double)v.y / 65536 + 0.5);
	}
	ERR(ae->GetADD(ID_LASTRANDX, &infoP->lastRandX));
	ERR(ae->GetADD(ID_LASTRANDY, &infoP->lastRandY));


	ERR(ae->GetFLOAT(ID_LINESIZE, &infoP->lineSize));
	ERR(ae->GetADD(ID_LINEMOVE, &infoP->lineMove));

	ERR(ae->GetADD(ID_SUB_COUNT, &infoP->subCount));
	ERR(ae->GetADD(ID_FOLD_COUNT, &infoP->foldCount));
	ERR(ae->GetADD(ID_DRAW_COUNT, &infoP->drawCount));


	PF_Fixed r;
	ERR(ae->GetANGLE(ID_OFFSET, &r));
	if (!err) {
		r = r % (360L << 16);
		if (r < 0) r += (360L << 16);
		infoP->offset = r / 65536;
	}
	ERR(ae->GetADD(ID_SEED, &infoP->seed));
	infoP->seed %= 30000;
	if (infoP->seed<0)infoP->seed += 30000;
	
	ERR(ae->GetCOLOR(ID_COLOR, &infoP->color));
	ERR(ae->GetCHECKBOX(ID_BLEND, &infoP->blend));


	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;

	//��ʂ��R�s�[
	ERR(ae->CopyInToOut());
	
	infoP->frame = ae->frame();


	if (ae->pixelFormat() == PF_PixelFormat_ARGB128) {
		CDraw32 cd(ae->output, ae->in_data);
		if (cd.world != NULL) {
			cd.exec(ae, infoP);
			if (infoP->blend == TRUE) {
				ERR(ae->iterate32((refconType)infoP, FilterImage32));
			}
		}

	}
	else if (ae->pixelFormat() == PF_PixelFormat_ARGB64) {
		CDraw16 cd(ae->output, ae->in_data);
		if (cd.world != NULL) {
			cd.exec(ae, infoP);
			if (infoP->blend == TRUE) {
				ERR(ae->iterate16((refconType)infoP, FilterImage16));
			}
		}
	}
	else if (ae->pixelFormat() == PF_PixelFormat_ARGB32) {
		CDraw8 cd(ae->output, ae->in_data);
		if (cd.world != NULL) {
			cd.exec(ae, infoP);
			if (infoP->blend == TRUE) {
				ERR(ae->iterate8((refconType)infoP, FilterImage8));
			}
		}
	}

	return err;
}

//-------------------------------------------------------------------------------------------------
//�����_�����O�̃��C��
/*
	SmartFX�ɑΉ����Ă��Ȃ��z�X�g(After Effects7�ȑO�̂���)�͂��̊֐����Ăяo����ĕ`�悷��
	���̊֐��������Ă����Έꉞv6.5�Ή��ɂȂ�
*/
static PF_Err 
Render ( 
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{

	PF_Err	err = PF_Err_NONE;
	PF_Handle		pixelTable = NULL;
	
	CFsAE ae(in_data,out_data,params,output,ID_NUM_PARAMS);
	err =ae.resultErr();
	if (!err){
		ParamInfo info;
		ERR(GetParams(&ae,&info));
		ERR(Exec(&ae,&info));
	}
	return err;
}
//-----------------------------------------------------------------------------------
/*
	SmartFX�Ή��̏ꍇ�A�܂����̊֐����Ă΂�ăp�����[�^�̊l�����s��
*/
#if defined(SUPPORT_SMARTFX)
static PF_Err
PreRender(
	PF_InData			*in_data,
	PF_OutData			*out_data,
	PF_PreRenderExtra	*extraP)
{
	PF_Err		err 		= PF_Err_NONE;
	CFsAE ae(in_data,out_data,extraP,sizeof(ParamInfo),ID_NUM_PARAMS);
	err = ae.resultErr();
	if (!err){

		ParamInfo *infoP = reinterpret_cast<ParamInfo*>(ae.LockPreRenderData());
		if (infoP){
			ae.SetHostPreRenderData();
			ERR(GetParams(&ae,infoP));
			ERR(ae.UnSetPreRenderData());
			ae.UnlockPreRenderData();
		}else{
			err = PF_Err_OUT_OF_MEMORY;
		}
	}
	return err;
}
#endif
//-----------------------------------------------------------------------------------
#if defined(SUPPORT_SMARTFX)
static PF_Err
SmartRender(
	PF_InData				*in_data,
	PF_OutData				*out_data,
	PF_SmartRenderExtra		*extraP)
{
	PF_Err			err		= PF_Err_NONE,
					err2 	= PF_Err_NONE;

	CFsAE ae(in_data,out_data,extraP,ID_NUM_PARAMS);
	err = ae.resultErr();
	if (!err){
		ParamInfo *infoP = reinterpret_cast<ParamInfo*>(ae.LockPreRenderData());
		if (infoP){
			ERR(Exec(&ae,infoP));
			ERR2(ae.UnsetSmartRender());
			ae.UnlockPreRenderData();
		}else{
			err = PF_Err_OUT_OF_MEMORY;
		}
	}
	return err;
}
#endif

#include "Fs_Entry.h"
