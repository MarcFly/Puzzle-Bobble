#ifndef	_MODULE_INPUT_H_
#define	_MODULE_INPUT_H_

#include "Include.h"

class ModuleInput : public Module {
public:
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	const unsigned char* key = nullptr;


};

#endif