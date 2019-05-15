/*
	F's Plugins AfterEffects 7.0 SDK
	FsGraphics
*/

#include "MainLineRepaint_old.h"


//-------------------------------------------------------------------------------------------------
// About�_�C�A���O
static PF_Err About (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_SPRINTF(	out_data->return_msg, 
				"%s, v%d.%d%d\r%s",
				STR(StrID_Name), 
				MAJOR_VERSION, 
				MINOR_VERSION,
				BUG_VERSION,
				STR(StrID_Description)
				);
	return PF_Err_NONE;
}

//-------------------------------------------------------------------------------------------------
static PF_Err GlobalSetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_Err	err = PF_Err_NONE;

	//AE_Effect.h�Œ�`�����PF_VERSION�}�N���ŋ��߂���l�����\�[�X�t�@�C����AE_Effect_Version�ƈ�v�����鎖
	out_data->my_version = PF_VERSION(	MAJOR_VERSION, 
										MINOR_VERSION,
										BUG_VERSION, 
										STAGE_VERSION, 
										BUILD_VERSION);

	//Output Flags
	//AE_Effect.h��Output Flags���Q��
	//16Bit�Ή��������w�ɂ�PF_OutFlag_DEEP_COLOR_AWARE��ǉ�����
	//
	//-------------------------------
	//�K�v�ȃt���[���̓����_�����O���Ȃ��B�ʏ�͂���B
	//���\�[�X�t�@�C����AE_Effect_Global_OutFlags�̒l��33555520
	/*
out_data->out_flags	|=
		PF_OutFlag_USE_OUTPUT_EXTENT	|
		PF_OutFlag_PIX_INDEPENDENT	|
		PF_OutFlag_DEEP_COLOR_AWARE;
	*/
	//-------------------------------
	//�m�C�Y���őS�t���[���`�悷��ꍇ�͂���
	//���\�[�X�t�@�C����AE_Effect_Global_OutFlags�̒l��33559620
	/*
out_data->out_flags	|=
		PF_OutFlag_NON_PARAM_VARY	|
		PF_OutFlag_USE_OUTPUT_EXTENT	|
		PF_OutFlag_PIX_INDEPENDENT	|
		PF_OutFlag_I_SHRINK_BUFFER	|
		PF_OutFlag_DEEP_COLOR_AWARE;
	*/
out_data->out_flags	|=
		PF_OutFlag_USE_OUTPUT_EXTENT	|
		PF_OutFlag_PIX_INDEPENDENT	|
		PF_OutFlag_DEEP_COLOR_AWARE;

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
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR(StrID_MY_Main_Color), 
					0x00,
					0x00,
					0x00,
					MY_Main_Color
					);

	//----------------------------------------------------------------
	out_data->num_params = 	MY_NUM_PARAMS; 

	return err;
}
//-------------------------------------------------------------------------------------------------

PF_Err CMainLineRepaint::getParams(
	PF_InData			*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_Err		err 		= PF_Err_NONE;
	if ( (params==NULL)||(output==NULL) ) {
		return 0xFF;
	}

	Main_Color			= params[MY_Main_Color]->u.cd.value;



	return err;
}

//-------------------------------------------------------------------------------------------------
//�����_�����O�̃��C��
static PF_Err Render (
	PF_InData			*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output )
{
	PF_Err		err 		= PF_Err_NONE;

	CMainLineRepaint exe(in_data,out_data,params,output);
	
	if  ( exe.Enabled() == FALSE ) {
		PF_SPRINTF(	out_data->return_msg, 
					"[%s] %s",
					STR(StrID_Name),
					STR(StrID_ERR_getParams)
					);
		return err;
	}
	
	//�摜�𕡎ʂ���
	exe.Copy();
	
	if (exe.is16Bit()==FALSE){
		exe.exec8();
	}else{
		exe.exec16();
	}
	return err;
}
//-------------------------------------------------------------------------------------------------
DllExport PF_Err EntryPointFunc(
	PF_Cmd			cmd,
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output,
	void			*extra)
{
	PF_Err		err = PF_Err_NONE;
	
	switch (cmd) {
		case PF_Cmd_ABOUT:
			err = About(in_data,out_data,params,output);
			break;
		case PF_Cmd_GLOBAL_SETUP:
			err = GlobalSetup(in_data,out_data,params,output);
			break;
		case PF_Cmd_PARAMS_SETUP:
			err = ParamsSetup(in_data,out_data,params,output);
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
	}
	return err;
}
//-------------------------------------------------------------------------------------------------
