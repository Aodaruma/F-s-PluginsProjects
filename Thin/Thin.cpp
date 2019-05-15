//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------


#include "Thin.h"


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
	PF_ADD_SLIDER(	STR_VALUE,	//�p�����[�^�̖��O
					0, 			//���l���͂���ꍇ�̍ŏ��l
					16,			//���l���͂���ꍇ�̍ő�l
					0,			//�X���C�_�[�̍ŏ��l 
					4,			//�X���C�_�[�̍ő�l
					0,			//�f�t�H���g�̒l
					ID_VALUE
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
					0x05,
					0x05,
					0x05,
					ID_COLOR1
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_COLOR2_ON,
					STR_ON,
					FALSE,
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
					FALSE,
					0,
					ID_COLOR3_ON
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR3, 
					0xFF,
					0x00,
					0x00,
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
					0xFF,
					0x00,
					ID_COLOR4
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
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_WHITE,
					STR_ON,
					FALSE,
					0,
					ID_WHITE
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_ALPHAZERO,
					STR_ON,
					FALSE,
					0,
					ID_ALPHAZERO
					);

	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_EDGE,
					STR_ON,
					FALSE,
					0,
					ID_EDGE
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
static PF_Err 
FilterImage8 (
	refconType		refcon, 
	A_long		xL, 
	A_long		yL, 
	PF_Pixel8	*inP, 
	PF_Pixel8	*outP)
{
	PF_Err			err = PF_Err_NONE;
	ParamInfo *	niP		= reinterpret_cast<ParamInfo*>(refcon);


	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
FilterImage16 (
	refconType	refcon, 
	A_long		xL, 
	A_long		yL, 
	PF_Pixel16	*inP, 
	PF_Pixel16	*outP)
{
	PF_Err			err = PF_Err_NONE;
	ParamInfo *	niP		= reinterpret_cast<ParamInfo*>(refcon);


	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
FilterImage32 (
	refconType	refcon, 
	A_long		xL, 
	A_long		yL, 
	PF_PixelFloat	*inP, 
	PF_PixelFloat	*outP)
{
	PF_Err			err = PF_Err_NONE;
	ParamInfo *	niP		= reinterpret_cast<ParamInfo*>(refcon);

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
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;

	ERR(ae->GetADD(ID_VALUE,&infoP->value));

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
	infoP->colorMax = idx;

	ERR(ae->GetFLOAT(ID_LEVEL,&infoP->level));
	infoP->level/=100;

	ERR(ae->GetCHECKBOX(ID_WHITE,&infoP->white));
	ERR(ae->GetCHECKBOX(ID_ALPHAZERO,&infoP->alphaZero));
	ERR(ae->GetCHECKBOX(ID_EDGE,&infoP->edge));

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;

	//��ʂ��R�s�[
	ERR(ae->CopyInToOut());
	
	if ( (infoP->colorMax<=0)||(infoP->value<=0))
	{
		return err;
	}
	switch(ae->pixelFormat())
	{
	case PF_PixelFormat_ARGB128:
		//ERR(ae->iterate32((refconType)infoP,FilterImage32));
		ERR(thinExec32(ae,infoP));
		break;
	case PF_PixelFormat_ARGB64:
		//ERR(ae->iterate16((refconType)infoP,FilterImage16));
		ERR(thinExec16(ae,infoP));
		break;
	case PF_PixelFormat_ARGB32:
		//ERR(ae->iterate8((refconType)infoP,FilterImage8));
		ERR(thinExec8(ae,infoP));
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
