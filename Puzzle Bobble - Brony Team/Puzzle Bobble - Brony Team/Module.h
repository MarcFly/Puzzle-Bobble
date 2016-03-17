#ifndef _MODULE_H_
#define _MODULE_H_

#include "Include.h"
#include "Globals.h"

class Module {
public:
	virtual bool Init();
	virtual update_status PreUpdate() { return update_status::UPDATE_CONTINUE; }
	virtual update_status Update() { return update_status::UPDATE_CONTINUE; }
	virtual update_status PostUpdate() { return update_status::UPDATE_CONTINUE; }
	virtual bool CleanUp() { return true; }
};

#endif
