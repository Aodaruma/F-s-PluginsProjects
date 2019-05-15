//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------


#include "IroTore.h"


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
	PF_ADD_CHECKBOX(STR_LINE_ONLY,
					STR_ON,
					FALSE,
					0,
					ID_LINE_ONLY
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR1_ON,
					STR_ON,
					TRUE,
					0,
					ID_COLOR1_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR1, 
					0x0F,
					0x0F,
					0x0F,
					ID_COLOR1
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR2_ON,
					STR_ON,
					TRUE,
					0,
					ID_COLOR2_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR2, 
					0x0A,
					0x0A,
					0x0A,
					ID_COLOR2
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR3_ON,
					STR_ON,
					TRUE,
					0,
					ID_COLOR3_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR3, 
					0x05,
					0x05,
					0x05,
					ID_COLOR3
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR4_ON,
					STR_ON,
					FALSE,
					0,
					ID_COLOR4_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR4, 
					0x00,
					0x00,
					0x00,
					ID_COLOR4
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR5_ON,
					STR_ON,
					FALSE,
					0,
					ID_COLOR5_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR5, 
					0x00,
					0x00,
					0x00,
					ID_COLOR5
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR6_ON,
					STR_ON,
					FALSE,
					0,
					ID_COLOR6_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR6, 
					0x00,
					0x00,
					0x00,
					ID_COLOR6
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LEVEL,	//Name
						0,						//VALID_MIN
						100,						//VALID_MAX
						0,						//SLIDER_MIN
						10,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						0,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LEVEL
						);

	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_IG_COLOR, 
					0x10,
					0x10,
					0x10,
					ID_IG_COLOR
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE_MINMAX1,	//�p�����[�^�̖��O
					-50, 		//���l���͂���ꍇ�̍ŏ��l
					50,			//���l���͂���ꍇ�̍ő�l
					-10,				//�X���C�_�[�̍ŏ��l 
					10,			//�X���C�_�[�̍ő�l
					-2,				//�f�t�H���g�̒l
					ID_LINE_MINMAX1
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE_MINMAX2,	//�p�����[�^�̖��O
					-50, 		//���l���͂���ꍇ�̍ŏ��l
					50,			//���l���͂���ꍇ�̍ő�l
					-10,				//�X���C�_�[�̍ŏ��l 
					10,			//�X���C�_�[�̍ő�l
					0,				//�f�t�H���g�̒l
					ID_LINE_MINMAX2
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE_BLUR,	//�p�����[�^�̖��O
					0, 		//���l���͂���ꍇ�̍ŏ��l
					50,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					10,			//�X���C�_�[�̍ő�l
					4,				//�f�t�H���g�̒l
					ID_LINE_BLUR
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_LINE_H,0,ID_LINE_H); 
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINE_S,	//Name
						-100,						//VALID_MIN
						100,						//VALID_MAX
						-100,						//SLIDER_MIN
						100,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						0,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LINE_S
						);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINE_L,	//Name
						-100,						//VALID_MIN
						100,						//VALID_MAX
						-100,						//SLIDER_MIN
						100,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						-50,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LINE_L
						);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINE_R,	//Name
						-100,						//VALID_MIN
						100,						//VALID_MAX
						-100,						//SLIDER_MIN
						100,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						0,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LINE_RED
						);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINE_G,	//Name
						-100,						//VALID_MIN
						100,						//VALID_MAX
						-100,						//SLIDER_MIN
						100,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						0,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LINE_GREEN
						);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FLOAT_SLIDER(STR_LINE_B,	//Name
						-100,						//VALID_MIN
						100,						//VALID_MAX
						-100,						//SLIDER_MIN
						100,						//SLIDER_MAX
						1,						//CURVE_TOLERANCE
						0,						//DFLT
						1,						//PREC
						0,						//DISP
						0,						//WANT_PHASE
						ID_LINE_BLUE
						);	
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_NEG_COLOR1_ON,
					STR_ON,
					FALSE,
					0,
					ID_NEG_COLOR1_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_NEG_COLOR1, 
					0xFE,
					0xFE,
					0xFE,
					ID_NEG_COLOR1
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_NEG_COLOR2_ON,
					STR_ON,
					FALSE,
					0,
					ID_NEG_COLOR2_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_NEG_COLOR2, 
					0xFD,
					0xFD,
					0xFD,
					ID_NEG_COLOR2
					);

	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_NEG_COLOR3_ON,
					STR_ON,
					FALSE,
					0,
					ID_NEG_COLOR3_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_NEG_COLOR3, 
					0xFC,
					0xFC,
					0xFC,
					ID_NEG_COLOR3
					);

	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_NEG_COLOR4_ON,
					STR_ON,
					FALSE,
					0,
					ID_NEG_COLOR4_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_NEG_COLOR4, 
					0xFC,
					0xFC,
					0xFC,
					ID_NEG_COLOR4
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
	PF_Err				err					= PF_Err_NONE;
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
	PF_Err 	err 	= PF_Err_NONE;
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Boolean FindColor(ParamInfo *infoP, PF_Pixel p)
{
	PF_Boolean ret = FALSE;
	if (infoP->colorMax >0 ) {
		for ( int i=0; i<infoP->colorMax; i++){
			if (
				(p.blue == infoP->color[i].blue)
				&&(p.green == infoP->color[i].green)
				&&(p.red == infoP->color[i].red)){
			
				ret = TRUE;
				break;
			}

		}
	}
	return ret;
}
//-------------------------------------------------------------------------------------------------
static PF_Boolean FindNegColor(ParamInfo *infoP, PF_Pixel p)
{
	PF_Boolean ret = FALSE;
	if (infoP->ngColorMax >0 ) {
		for ( int i=0; i<infoP->ngColorMax; i++){
			if (
				(p.blue == infoP->ngColor[i].blue)
				&&(p.green == infoP->ngColor[i].green)
				&&(p.red == infoP->ngColor[i].red)){
			
				ret = TRUE;
				break;
			}

		}
	}
	return ret;
}
//-------------------------------------------------------------------------------------------------
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;



	ERR(ae->GetCHECKBOX(ID_LINE_ONLY,&infoP->lineOnly));


	PF_Boolean on = FALSE;
	int idx = 0;
	PF_Pixel p = {0,0,0,0};
	infoP->colorMax = 0;
	ERR(ae->GetCHECKBOX(ID_COLOR1_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR1,&p));
		infoP->color[idx] = p;
		idx++;
	}
	ERR(ae->GetCHECKBOX(ID_COLOR2_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR2,&p));
		if ( FindColor(infoP,p) == FALSE) { 
			infoP->color[idx] = p;
			idx++;
		}
	}
	ERR(ae->GetCHECKBOX(ID_COLOR3_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR3,&p));
		if ( FindColor(infoP,p) == FALSE) { 
			infoP->color[idx] = p;
			idx++;
		}
	}
	ERR(ae->GetCHECKBOX(ID_COLOR4_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR4,&p));
		if ( FindColor(infoP,p)==FALSE) { 
			infoP->color[idx] = p;
			idx++;
		}
	}
	ERR(ae->GetCHECKBOX(ID_COLOR5_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR5,&p));
		infoP->color[idx] = p;
		idx++;
	}
	ERR(ae->GetCHECKBOX(ID_COLOR6_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_COLOR6,&p));
		infoP->color[idx] = p;
		idx++;
	}
	infoP->colorMax = idx;

	double lv = 0;
	ERR(ae->GetFLOAT(ID_LEVEL,&lv));
	infoP->level = (A_long)((double)PF_MAX_CHAN8 * lv / 100.0 + 0.5);	


	ERR(ae->GetCOLOR(ID_IG_COLOR,&infoP->igColor));

	ERR(ae->GetADD(ID_LINE_MINMAX1,&infoP->minmax1));
	ERR(ae->GetADD(ID_LINE_MINMAX2,&infoP->minmax2));
	ERR(ae->GetADD(ID_LINE_BLUR,&infoP->blur));


	PF_Fixed r = 0;
	infoP->hue = 0.0;
	ERR(ae->GetANGLE(ID_LINE_H,&r));
	r = r % (360L<<16);
	if (r <0) r += (360L<<16);
	infoP->hue = ((double)r / (double)(1L<<16))/360.0;

	ERR(ae->GetFLOAT(ID_LINE_S,&infoP->sat));
	ERR(ae->GetFLOAT(ID_LINE_L,&infoP->light));
	ERR(ae->GetFLOAT(ID_LINE_RED,&infoP->red));
	ERR(ae->GetFLOAT(ID_LINE_GREEN,&infoP->green));
	ERR(ae->GetFLOAT(ID_LINE_BLUE,&infoP->blue));
	infoP->sat /= 100.0;
	infoP->light /= 100.0;
	infoP->red /= 100.0;
	infoP->green /= 100.0;
	infoP->blue /= 100.0;

	idx = 0;
	infoP->ngColorMax = 0;

	ERR(ae->GetCHECKBOX(ID_NEG_COLOR1_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_NEG_COLOR1,&p));
		if ( FindColor(infoP,p)==FALSE) { 
			infoP->ngColor[idx] = p;
			idx++;
		}		
	}
	ERR(ae->GetCHECKBOX(ID_NEG_COLOR2_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_NEG_COLOR2,&p));
		if ( FindColor(infoP,p)==FALSE) { 
			if ( FindNegColor(infoP,p)==FALSE) { 
				infoP->ngColor[idx] = p;
				idx++;
			}
		}		
	}
	ERR(ae->GetCHECKBOX(ID_NEG_COLOR3_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_NEG_COLOR3,&p));
		if ( FindColor(infoP,p)==FALSE) { 
			if ( FindNegColor(infoP,p)==FALSE) { 
				infoP->ngColor[idx] = p;
				idx++;
			}
		}		
	}
	ERR(ae->GetCHECKBOX(ID_NEG_COLOR4_ON,&on));
	if (on==TRUE) {
		ERR(ae->GetCOLOR(ID_NEG_COLOR4,&p));
		if ( FindColor(infoP,p)==FALSE) { 
			if ( FindNegColor(infoP,p)==FALSE) { 
				infoP->ngColor[idx] = p;
				idx++;
			}
		}		
	}
	infoP->ngColorMax = idx;
	return err;
}
//###########################################################################
static ParamInfo16 
	infoTo16 (ParamInfo *infoP)
{
	ParamInfo16 ret;
	ret.lineOnly = infoP->lineOnly;
	ret.colorMax = infoP->colorMax;
	if (infoP->colorMax>0){
		for (int i=0;i<infoP->colorMax;i++){
			ret.color[i] = infoP->color[i];
		}
	}


	ret.level = infoP->level;
	ret.igColor = CONV8TO16(infoP->igColor);
	ret.blur = infoP->blur;
	ret.minmax1 = infoP->minmax1;
	ret.minmax2 = infoP->minmax2;
	ret.hue = infoP->hue;
	ret.sat = infoP->sat;
	ret.light = infoP->light;
	ret.red = infoP->red;
	ret.green = infoP->green;
	ret.blue = infoP->blue;

	ret.ngColorMax = infoP->ngColorMax;
	if (infoP->ngColorMax>0){
		for (int i=0;i<infoP->ngColorMax;i++){
			ret.ngColor[i] = infoP->ngColor[i];
		}
	}

	return ret;

}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;

	//��ʂ��R�s�[
	ERR(ae->CopyInToOut());
	
	if (infoP->colorMax<=0)
	{
		return err;
	}
	switch(ae->pixelFormat())
	{
	case PF_PixelFormat_ARGB128:
		//ParamInfo32 info32;

		//info32 = infoTo32(infoP);
		//ERR(irotoreExec32(ae,&info32));
		break;
	case PF_PixelFormat_ARGB64:
		ParamInfo16 info16;

		info16 = infoTo16(infoP);
		ERR(irotoreExec16(ae,&info16));
		break;
	case PF_PixelFormat_ARGB32:
		ERR(irotoreExec8(ae,infoP));
		break;
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
