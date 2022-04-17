#include <opnet.h>
#include <ema.h>
#include <opnet_emadefs.h>
#include <opnet_constants.h>
#include <math.h>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#include "math.h"
#include "conio.h"

#define UE_NUM  1000


double  Random_x();
double Random_y();
/* array for all textlist attributes in model */
Prg_List*		prg_lptr [5];

/* array for all objects in model */
EmaT_Object_Id		obj [11+UE_NUM];



int
main (int argc, char* argv [])
	{
	EmaT_Model_Id			model_id;
	int					i=0;
	int obj_index = 11;
	int UE_count = 0;
	double x;
	double y;

	/* initialize EMA package */
	Ema_Init (EMAC_MODE_ERR_PRINT | EMAC_MODE_REL_60, argc, argv);

	/* create an empty model */
	model_id = Ema_Model_Create (MOD_NETWORK);



	/* create all objects */
	obj [0] = Ema_Object_Create (model_id, OBJ_NT_SUBNET_FIX);
	obj [1] = Ema_Object_Create (model_id, OBJ_NT_SUBNET_VIEW);
	obj [2] = Ema_Object_Create (model_id, OBJ_NT_SUBNET_VIEW);
	obj [3] = Ema_Object_Create (model_id, OBJ_NT_SUBNET_FIX);
	obj [4] = Ema_Object_Create (model_id, OBJ_NT_SUBNET_VIEW);
	obj [5] = Ema_Object_Create (model_id, OBJ_NT_NODE_FIXED);
	obj [6] = Ema_Object_Create (model_id, OBJ_NT_ISO_ELEV_MAP_COLOR_SETTING);
	obj [7] = Ema_Object_Create (model_id, OBJ_NT_ISO_ELEV_MAP_COLOR_SETTING);
	obj [8] = Ema_Object_Create (model_id, OBJ_NT_ISO_ELEV_MAP_COLOR_SETTING);
	obj [9] = Ema_Object_Create (model_id, OBJ_NT_ISO_ELEV_MAP_COLOR_SETTING);
	obj [10] = Ema_Object_Create (model_id, OBJ_NT_ISO_ELEV_MAP_COLOR_SETTING);
	for(i = 0;i < UE_NUM;i++)
	{
		obj[11+i] = Ema_Object_Create (model_id, OBJ_NT_NODE_FIXED);
	}




	/* set the model level attributes */
	/* create and init prg list 'prg_lptr [0]' */
	prg_lptr [0] = (Prg_List *)prg_list_create ();
	/* create and init prg list 'prg_lptr [1]' */
	prg_lptr [1] = (Prg_List *)prg_list_create ();
	prg_list_strings_append (prg_lptr [1], 
		"custom_model_list",
		"internet_toolbox",
		PRGC_NIL);

	/* create and init prg list 'prg_lptr [2]' */
	prg_lptr [2] = (Prg_List *)prg_list_create ();
	Ema_Model_Attr_Set (model_id,
		"ext fileset",          COMP_CONTENTS, prg_lptr [0],
		"keywords list",        COMP_CONTENTS, prg_lptr [1],
		"view subnet",          COMP_CONTENTS, obj [0],
		"iso elev map color levels",COMP_ARRAY_CONTENTS (0), obj [6],
		"iso elev map color levels",COMP_ARRAY_CONTENTS (1), obj [7],
		"iso elev map color levels",COMP_ARRAY_CONTENTS (2), obj [8],
		"iso elev map color levels",COMP_ARRAY_CONTENTS (3), obj [9],
		"iso elev map color levels",COMP_ARRAY_CONTENTS (4), obj [10],
		"iso elev map label color",COMP_CONTENTS, 0,
		"view index list",      COMP_CONTENTS, prg_lptr [2],
		EMAC_EOL);



	/* assign attrs for object 'obj [0]' */
	/* create and init prg list 'prg_lptr [3]' */
	prg_lptr [3] = (Prg_List *)prg_list_create ();
	Ema_Object_Attr_Set (model_id, obj [0], 
		"name",                 COMP_CONTENTS, "top",
		"name",                 COMP_USER_INTENDED, EMAC_ENABLED,
		"x position",           COMP_CONTENTS, (double) 0,
		"x position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"y position",           COMP_CONTENTS, (double) 0,
		"y position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"x span",               COMP_CONTENTS, (double) 360,
		"x span",               COMP_USER_INTENDED, EMAC_ENABLED,
		"y span",               COMP_CONTENTS, (double) 180,
		"y span",               COMP_USER_INTENDED, EMAC_ENABLED,
		"icon name",            COMP_CONTENTS, "subnet",
		"icon name",            COMP_INTENDED, EMAC_DISABLED,
		"map",                  COMP_CONTENTS, "world",
		"map",                  COMP_USER_INTENDED, EMAC_ENABLED,
		"subnet",               COMP_CONTENTS, EMAC_NULL_OBJ_ID,
		"view stack",           COMP_ARRAY_CONTENTS (0), obj [1],
		EMAC_EOL);

	Ema_Object_Attr_Set (model_id, obj [0], 
		"view stack",           COMP_ARRAY_CONTENTS (1), obj [2],
		"grid unit",            COMP_CONTENTS, 5,
		"ui status",            COMP_CONTENTS, 0,
		"iso-elev-map list",    COMP_CONTENTS, prg_lptr [3],
		"iso-elev-map line threshold",COMP_CONTENTS, (double) 50,
		"view",                 COMP_CONTENTS, "Default View",
		"view mode",            COMP_CONTENTS, 0,
		"view positions",       COMP_INTENDED, EMAC_DISABLED,
		EMAC_EOL);


	/* assign attrs for object 'obj [3]' */
	/* create and init prg list 'prg_lptr [4]' */
	prg_lptr [4] = (Prg_List *)prg_list_create ();
	Ema_Object_Attr_Set (model_id, obj [3], 
		"name",                 COMP_CONTENTS, "subnet",
		"name",                 COMP_USER_INTENDED, EMAC_ENABLED,
		"user id",              COMP_CONTENTS, 0,
		"user id",              COMP_USER_INTENDED, EMAC_ENABLED,
		"x position",           COMP_CONTENTS, (double) 0,
		"x position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"y position",           COMP_CONTENTS, (double) 0,
		"y position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"x span",               COMP_CONTENTS, (double) 360,
		"x span",               COMP_USER_INTENDED, EMAC_ENABLED,
		"y span",               COMP_CONTENTS, (double) 180,
		"y span",               COMP_USER_INTENDED, EMAC_ENABLED,
		"priority",             COMP_CONTENTS, 0,
		"priority",             COMP_USER_INTENDED, EMAC_ENABLED,
		"outline color",        COMP_CONTENTS, 3,
		"outline color",        COMP_USER_INTENDED, EMAC_ENABLED,
		EMAC_EOL);

	Ema_Object_Attr_Set (model_id, obj [3], 
		"icon name",            COMP_CONTENTS, "subnet",
		"icon name",            COMP_INTENDED, EMAC_DISABLED,
		"icon name",            COMP_USER_INTENDED, EMAC_ENABLED,
		"map",                  COMP_CONTENTS, "world",
		"map",                  COMP_USER_INTENDED, EMAC_ENABLED,
		"subnet",               COMP_CONTENTS, obj [0],
		"view stack",           COMP_ARRAY_CONTENTS (0), obj [4],
		"grid unit",            COMP_CONTENTS, 5,
		"ui status",            COMP_CONTENTS, 0,
		"iso-elev-map list",    COMP_CONTENTS, prg_lptr [4],
		"iso-elev-map line threshold",COMP_CONTENTS, (double) 50,
		"view",                 COMP_CONTENTS, "Default View",
		"view mode",            COMP_CONTENTS, 0,
		"view positions",       COMP_INTENDED, EMAC_DISABLED,
		EMAC_EOL);


	/* assign attrs for object 'obj [5]' */
	Ema_Object_Attr_Set (model_id, obj [5], 
		"name",                 COMP_CONTENTS, "node_0",
		"name",                 COMP_USER_INTENDED, EMAC_ENABLED,
		"model",                COMP_CONTENTS, "NTN_SAT_UE",
		"model",                COMP_USER_INTENDED, EMAC_ENABLED,
		"x position",           COMP_CONTENTS, (double) -15.9,
		"x position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"y position",           COMP_CONTENTS, (double) 28.3,
		"y position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"doc file",             COMP_CONTENTS, "",
		"doc file",             COMP_INTENDED, EMAC_DISABLED,
		"doc file",             COMP_USER_INTENDED, EMAC_ENABLED,
		"subnet",               COMP_CONTENTS, obj [3],
		"alias",                COMP_INTENDED, EMAC_DISABLED,
		"tooltip",              COMP_CONTENTS, "",
		"tooltip",              COMP_INTENDED, EMAC_DISABLED,
		"tooltip",              COMP_USER_INTENDED, EMAC_ENABLED,
		EMAC_EOL);

	Ema_Object_Attr_Set (model_id, obj [5], 
		"ui status",            COMP_CONTENTS, 0,
		"view positions",       COMP_INTENDED, EMAC_DISABLED,
		EMAC_EOL);


	/* assign attrs for object 'obj [1]' */
	Ema_Object_Attr_Set (model_id, obj [1], 
		"min x",                COMP_CONTENTS, (double) -180,
		"min y",                COMP_CONTENTS, (double) 90,
		"sbar x",               COMP_CONTENTS, (double) 0,
		"sbar y",               COMP_CONTENTS, (double) 0,
		"grid step",            COMP_CONTENTS, (double) 15,
		"resolution",           COMP_CONTENTS, (double) 2.5,
		"grid style",           COMP_CONTENTS, 2,
		"grid color",           COMP_CONTENTS, 21,
		EMAC_EOL);


	/* assign attrs for object 'obj [2]' */
	Ema_Object_Attr_Set (model_id, obj [2], 
		"min x",                COMP_CONTENTS, (double) -179.999725341797,
		"min y",                COMP_CONTENTS, (double) 83.6025009155273,
		"sbar x",               COMP_CONTENTS, (double) 0,
		"sbar y",               COMP_CONTENTS, (double) 0,
		"grid step",            COMP_CONTENTS, (double) 25,
		"resolution",           COMP_CONTENTS, (double) 3.30632805740627,
		"grid style",           COMP_CONTENTS, 2,
		"grid color",           COMP_CONTENTS, 21,
		EMAC_EOL);


	/* assign attrs for object 'obj [4]' */
	Ema_Object_Attr_Set (model_id, obj [4], 
		"min x",                COMP_CONTENTS, (double) -180,
		"min y",                COMP_CONTENTS, (double) 90,
		"sbar x",               COMP_CONTENTS, (double) 0,
		"sbar y",               COMP_CONTENTS, (double) 0,
		"grid step",            COMP_CONTENTS, (double) 22.5,
		"resolution",           COMP_CONTENTS, (double) 3.30833333333333,
		"grid style",           COMP_CONTENTS, 2,
		"grid color",           COMP_CONTENTS, 21,
		EMAC_EOL);


	/* assign attrs for object 'obj [6]' */
	Ema_Object_Attr_Set (model_id, obj [6], 
		"elevation",            COMP_CONTENTS, (double) 1e+100,
		"color",                COMP_CONTENTS, 1090519039,
		EMAC_EOL);


	/* assign attrs for object 'obj [7]' */
	Ema_Object_Attr_Set (model_id, obj [7], 
		"elevation",            COMP_CONTENTS, (double) 5000,
		"color",                COMP_CONTENTS, 1073741824,
		EMAC_EOL);


	/* assign attrs for object 'obj [8]' */
	Ema_Object_Attr_Set (model_id, obj [8], 
		"elevation",            COMP_CONTENTS, (double) 3000,
		"color",                COMP_CONTENTS, 1086806624,
		EMAC_EOL);


	/* assign attrs for object 'obj [9]' */
	Ema_Object_Attr_Set (model_id, obj [9], 
		"elevation",            COMP_CONTENTS, (double) 1000,
		"color",                COMP_CONTENTS, 1073745152,
		EMAC_EOL);


	/* assign attrs for object 'obj [10]' */
	Ema_Object_Attr_Set (model_id, obj [10], 
		"elevation",            COMP_CONTENTS, (double) 1,
		"color",                COMP_CONTENTS, 1079591136,
		EMAC_EOL);


	/* assign attrs for object 'obj [11]-[20]' */

	for(i = 0;i < UE_NUM;i++)
	{
		char UE_name[15];

		memset(UE_name, 0, 15);
		sprintf(UE_name, "SAT_UE_%d", UE_count);
		x = Random_x();
		y = Random_y();
	Ema_Object_Attr_Set (model_id, obj [obj_index], 
		"name",                 COMP_CONTENTS, UE_name,
		"name",                 COMP_USER_INTENDED, EMAC_ENABLED,
		"model",                COMP_CONTENTS, "NTN_SAT_UE",
		"model",                COMP_USER_INTENDED, EMAC_ENABLED,
		"x position",           COMP_CONTENTS, (double) x,
		"x position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"y position",           COMP_CONTENTS, (double) y,
		"y position",           COMP_USER_INTENDED, EMAC_ENABLED,
		"doc file",             COMP_CONTENTS, "",
		"doc file",             COMP_INTENDED, EMAC_DISABLED,
		"doc file",             COMP_USER_INTENDED, EMAC_ENABLED,
		"subnet",               COMP_CONTENTS, obj [3],
		"alias",                COMP_INTENDED, EMAC_DISABLED,
		"tooltip",              COMP_CONTENTS, "",
		"tooltip",              COMP_INTENDED, EMAC_DISABLED,
		"tooltip",              COMP_USER_INTENDED, EMAC_ENABLED,
		EMAC_EOL);

	Ema_Object_Attr_Set (model_id, obj [obj_index], 
		"ui status",            COMP_CONTENTS, 0,
		"view positions",       COMP_INTENDED, EMAC_DISABLED,
		EMAC_EOL);

		obj_index++;
		UE_count++;
		
	}
	







	/* write the model to application-readable form */
	Ema_Model_Write (model_id, "test_2");

	return 0;
	}

static double Random_x() 
{

		double x_coordinate = 0;
		//得到区间在[-180,180]的随机值

		//正负判定
		int flag = 1;
		int ranNum;
		int a;
		double b;
		double c;
		int i;
		int n;
		ranNum = rand() % 10 + 1;
		flag = ranNum <= 5 ? 1 : -1;

		//取得整数部分[0,179]
		a = rand() % 180;

		//取得小数部分11位
		b = 0;
		for (i = 0; i < 11; i++) {
			n = rand() % 10;
			b = b * 10 + n;
		}
		c = b * 0.00000000001;

		x_coordinate = flag * (a + c);
		return x_coordinate;
}

static double Random_y() 
{
    double y_coordinate = 0;
    //得到区间在[-90,90]的随机值

    //正负判定
    int flag = 1;
	int ranNum;
	int a;
	double b;
	double c;
	int i;
	int n;


    ranNum = rand() % 10 + 1;
    flag = ranNum <= 5 ? 1 : -1;

    //取得整数部分[0,89]
    a = rand() % 90;

    //取得小数部分11位
    b = 0;
    for (i = 0; i < 11; i++) {
        n = rand() % 10;
        b = b * 10 + n;
    }
    c = b * 0.00000000001;

    y_coordinate = flag * (a + c);
    return y_coordinate;
}

	

