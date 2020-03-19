//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------

#include "RandomShift.h"


//-------------------------------------------------------------------------------------------------
// About�_�C�A���O
static PF_Err About (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_Err	err				= PF_Err_NONE;
	CFsAE ae;
	err = ae.About(in_data,out_data,params,output);
	return err;
}

//-------------------------------------------------------------------------------------------------
static PF_Err GlobalSetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_Err	err				= PF_Err_NONE;
	CFsAE ae;
	err = ae.GlobalSetup(in_data,out_data,params,output);
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err GlobalSetdown(
	PF_InData	*in_data)
{
	PF_Err	err				= PF_Err_NONE;
	CFsAE ae;
	err = ae.GlobalSetdown(in_data);
	return err;
}

//-------------------------------------------------------------------------------------------------
static PF_Err SequenceSetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	return PF_Err_NONE;
}

//-------------------------------------------------------------------------------------------------
static PF_Err SequenceSetdown (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	return PF_Err_NONE;
}

//-------------------------------------------------------------------------------------------------
static PF_Err SequenceResetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	return PF_Err_NONE;
}

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
	PF_ADD_SLIDER(	STR_Y,	//�p�����[�^�̖��O
					0, 			//���l���͂���ꍇ�̍ŏ��l
					32000,		//���l���͂���ꍇ�̍ő�l
					0,			//�X���C�_�[�̍ŏ��l 
					3000,		//�X���C�_�[�̍ő�l
					1000,		//�f�t�H���g�̒l
					ID_Y
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_SHIFTMAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					2000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					5,			//�f�t�H���g�̒l
					ID_SHIFTMAX
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_SHIFTMIN,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					2000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					1,			//�f�t�H���g�̒l
					ID_SHIFTMIN
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LENGTHMAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					2000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					30,			//�f�t�H���g�̒l
					ID_LENGTHMAX
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LENGTHMAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					2000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					5,			//�f�t�H���g�̒l
					ID_LENGTHMIN
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_HEIGHTMAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					1000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					50,			//�X���C�_�[�̍ő�l
					30,			//�f�t�H���g�̒l
					ID_HEIGHTMAX
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_HEIGHTMIN,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					1000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					50,			//�X���C�_�[�̍ő�l
					5,			//�f�t�H���g�̒l
					ID_HEIGHTMIN
					);

	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_VERSHIFT_VALUE,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					1000,		//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					50,			//�X���C�_�[�̍ő�l
					0,			//�f�t�H���g�̒l
					ID_VERSHIFT_VALUE
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
	PF_Err				err					= PF_Err_NONE,
						err2				= PF_Err_NONE;
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
	PF_Err 	err 	= PF_Err_NONE,
			err2 	= PF_Err_NONE;
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;

	ERR(ae->GetADD(ID_Y,&infoP->value));
	
	ERR(ae->GetADD(ID_SHIFTMAX,&infoP->shiftMax));
	ERR(ae->GetADD(ID_SHIFTMIN,&infoP->shiftMin));
	if ( infoP->shiftMin>infoP->shiftMax) swapLong(&infoP->shiftMin,&infoP->shiftMax);

	ERR(ae->GetADD(ID_LENGTHMAX,&infoP->lengthMax));
	ERR(ae->GetADD(ID_LENGTHMIN,&infoP->lengthMin));
	if ( infoP->lengthMin>infoP->lengthMax) swapLong(&infoP->lengthMin,&infoP->lengthMax);

	ERR(ae->GetADD(ID_HEIGHTMAX,&infoP->heightMax));
	ERR(ae->GetADD(ID_HEIGHTMIN,&infoP->heightMin));
	if ( infoP->heightMin>infoP->heightMax) swapLong(&infoP->heightMin,&infoP->heightMax);

	infoP->vertualShift=0;
	ERR(ae->GetADD(ID_VERSHIFT_VALUE,&infoP->vertualShift));

	infoP->shift	= 0;
	infoP->length	= 0;
	infoP->height	= 0;

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec8 (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;
	A_long i,v,s,sv;
	FsPixelCopyParam pc;
	v = infoP->value;
	if ( v>0){	
		for (i=0; i<v; i++){
			pc.width	= F_RAND2(infoP->lengthMin,infoP->lengthMax);
			pc.height	= F_RAND2(infoP->heightMin,infoP->heightMax);

			pc.srcX = F_RAND2(-pc.width,ae->in->width());
			pc.srcY = F_RAND2(-pc.height,ae->in->height());
			s = F_RAND2(infoP->shiftMin,infoP->shiftMax);
			if ( (F_RAND() % 2)==1) s *=-1;
			sv=0;
			if ( infoP->vertualShift!=0){
				sv= F_RAND2(-infoP->vertualShift,infoP->vertualShift);
			}else{
				F_RAND();
			}
			if ((s!=0)||(sv!=0)){
				pc.dstX = pc.srcX + s;
				pc.dstY = pc.srcY + sv;
				ae->CopyInToOut8(&pc);
			}
		}
	}
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec16 (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;
	A_long i,v,s,sv;
	FsPixelCopyParam pc;
	v = infoP->value;
	if ( v>0){	
		for (i=0; i<v; i++){
			pc.width	= F_RAND2(infoP->lengthMin,infoP->lengthMax);
			pc.height	= F_RAND2(infoP->heightMin,infoP->heightMax);

			pc.srcX = F_RAND2(-pc.width,ae->in->width());
			pc.srcY = F_RAND2(-pc.height,ae->in->height());
			s = F_RAND2(infoP->shiftMin,infoP->shiftMax);
			if ( (F_RAND() % 2)==1) s *=-1;
			sv=0;
			if ( infoP->vertualShift!=0){
				sv= F_RAND2(-infoP->vertualShift,infoP->vertualShift);
			}else{
				F_RAND();
			}
			if ((s!=0)||(sv!=0)){
				pc.dstX = pc.srcX + s;
				pc.dstY = pc.srcY + sv;
				ae->CopyInToOut16(&pc);
			}
		}
	}
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec32 (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;
	A_long i,v,s,sv;
	FsPixelCopyParam pc;
	v = infoP->value;
	if ( v>0){	
		for (i=0; i<v; i++){
			pc.width	= F_RAND2(infoP->lengthMin,infoP->lengthMax);
			pc.height	= F_RAND2(infoP->heightMin,infoP->heightMax);

			pc.srcX = F_RAND2(-pc.width,ae->in->width());
			pc.srcY = F_RAND2(-pc.height,ae->in->height());
			s = F_RAND2(infoP->shiftMin,infoP->shiftMax);
			if ( (F_RAND() % 2)==1) s *=-1;
			sv=0;
			if ( infoP->vertualShift!=0){
				sv= F_RAND2(-infoP->vertualShift,infoP->vertualShift);
			}else{
				F_RAND();
			}
			if ((s!=0)||(sv!=0)){
				pc.dstX = pc.srcX + s;
				pc.dstY = pc.srcY + sv;
				ae->CopyInToOut32(&pc);
			}
		}
	}
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;

	//��ʂ��R�s�[
	ERR(ae->CopyInToOut());
	
	if (infoP->value>0){
		F_SRAND(ae->frame());
		switch(ae->pixelFormat())
		{
			case PF_PixelFormat_ARGB128:
				ERR(Exec32(ae,infoP));
				break;
			case PF_PixelFormat_ARGB64:
				ERR(Exec16(ae,infoP));
				break;
			case PF_PixelFormat_ARGB32:
				ERR(Exec8(ae,infoP));
				break;
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
		ERR(ae.CopyInToOut());
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
//-----------------------------------------------------------------------------------
static PF_Err 
RespondtoAEGP ( 	
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output,
	void*			extraP)
{
	PF_Err			err = PF_Err_NONE;
	
	AEGP_SuiteHandler suites(in_data->pica_basicP);
	
	suites.ANSICallbacksSuite1()->sprintf(	out_data->return_msg, 
											"%s",	
											reinterpret_cast<A_char*>(extraP));

	return err;
}

//-----------------------------------------------------------------------------------
DllExport	PF_Err 
EntryPointFunc (
	PF_Cmd			cmd,
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output,
	void			*extraP)
{
	PF_Err		err = PF_Err_NONE;
	
	try
	{
		CFsAE ae;
		switch (cmd) {
			case PF_Cmd_ABOUT:
				err = About(in_data,out_data,params,output);
				break;
			case PF_Cmd_GLOBAL_SETUP:
				err = GlobalSetup(	in_data,out_data,params,output);
				break;
			case PF_Cmd_GLOBAL_SETDOWN:
				err = GlobalSetdown(in_data);
				break;
			case PF_Cmd_PARAMS_SETUP:
				err = ParamsSetup(	in_data,out_data,params,output);
				break;
			case PF_Cmd_SEQUENCE_SETUP:
				err = SequenceSetup(in_data,out_data,params,output);
				break;
			case PF_Cmd_SEQUENCE_SETDOWN:
				err = SequenceSetdown(in_data,out_data,params,output);
				break;
			case PF_Cmd_SEQUENCE_RESETUP:
				err = SequenceResetup(in_data,out_data,params,output);
				break;
			case PF_Cmd_RENDER:
					err = Render(in_data,out_data,params,output);
					break;
#if defined(SUPPORT_SMARTFX)
			case PF_Cmd_SMART_PRE_RENDER:
				err = PreRender(in_data,out_data,reinterpret_cast<PF_PreRenderExtra*>(extraP));
				break;
			case PF_Cmd_SMART_RENDER:
				err = SmartRender(	in_data,out_data,reinterpret_cast<PF_SmartRenderExtra*>(extraP));
				break;
#endif
			case PF_Cmd_COMPLETELY_GENERAL:
				err = RespondtoAEGP(in_data,out_data,params,output,extraP);
				break;
			case PF_Cmd_DO_DIALOG:
				//err = PopDialog(in_data,out_data,params,output);
				break;		
			case PF_Cmd_USER_CHANGED_PARAM:
				err = HandleChangedParam(	in_data,
											out_data,
											params,
											output, 
											reinterpret_cast<PF_UserChangedParamExtra*>(extraP));
				break;
			case PF_Cmd_QUERY_DYNAMIC_FLAGS:
				err = QueryDynamicFlags(in_data,
										out_data,
										params,
										reinterpret_cast<PF_UserChangedParamExtra*>(extraP));
				break;
		}
	}
	catch(PF_Err &thrown_err){
		err = thrown_err;
	}
	return err;
}

//-------------------------------------------------------------------------------------------------
