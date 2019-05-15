/* MainLineRepaint_Strings.cpp */

#include "MainLineRepaint_old.h"

typedef struct {
	unsigned long	index;
	char			str[256];
} TableString;

TableString		g_strs[StrID_NUMTYPES] = {
	StrID_NONE,					"",
	StrID_Name,					"F's MainLineRepaint",
	StrID_Description,			"�Z����̎���𖳂����܂�",
	StrID_MADEBY,				"bry-ful",
	
	StrID_MY_Main_Color,		"����̐F",

	StrID_ERR_getFsAEParams,	"�摜�o�b�t�@�[�T�C�Y�G���[�ł��B��ƂȂ����B",
	StrID_ERR_getParams,	"�p�����[�^�G���[�ł��B��ƂȂ����B",
};


char *GetStringPtr(int strNum)
{
	return g_strs[strNum].str;
}
	
