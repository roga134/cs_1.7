#include "ct.h"

CT::CT()
{
	HaveKitDef = 0;
	IsBoombDef = 0;
}
		
CT::CT(CT& SCT)
{
	HaveKitDef = SCT.GetHaveKitDef();
	IsBoombDef = SCT.GetIsBoombDef();
}
		
CT::CT(bool SHaveKitDef , bool SIsBoombDef)
{
	HaveKitDef = SHaveKitDef;
	IsBoombDef = SIsBoombDef;
}

CT::~CT() {}

void CT::SetHaveKitDef(bool SHaveKitDef)
{
	HaveKitDef = SHaveKitDef;
}
		
void CT::SetIsBoombDef(bool SIsBoombDef)
{
	IsBoombDef = SIsBoombDef;
}

bool CT::GetHaveKitDef()
{
	return HaveKitDef;
}
	
bool CT::GetIsBoombDef()
{
	return IsBoombDef;
}

bool CT::operator==(CT& SCT)
{
	if (IsBoombDef != SCT.GetIsBoombDef())
	{
		return 0;
	}
	if (HaveKitDef != SCT.GetHaveKitDef())
	{
		return 0;
	}
	return 1;
}

bool CT::operator!=(CT& SCT)
{
	if (IsBoombDef != SCT.GetIsBoombDef())
	{
		return 1;
	}
	if (HaveKitDef != SCT.GetHaveKitDef())
	{
		return 1;
	}
	return 0;
}

void CT::operator=(CT& SCT)
{
	HaveKitDef = SCT.GetHaveKitDef();
	IsBoombDef = SCT.GetIsBoombDef();
}