#ifndef HEADER_STRUCTS
#define HEADER_STRUCTS
#include <stdbool.h>

struct IDentification_Name_Header {
	 bool (*isValid)(char*);
	 char* typePtr;
	 char* structNameString;
};

struct USAF_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct NCDC_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Date_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct HrMn_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct I_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Type_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct QCP_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Wind_Dir_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Wind_Spd_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Wind_Spd_Q_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Temp_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Temp_Q_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Dewpt_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Dewpt_Q_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct Slp_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

struct RHx_Header {
	bool (*isValid)(char*);
	char* typePtr;
	char* structNameString;
};

#endif