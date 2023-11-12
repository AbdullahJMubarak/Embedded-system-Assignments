
#include <avr/io.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_interface.h"

void GIE_voidEnableGlobalInterrupt()
{
	SET_BIT(SREG,7);
}

void GIE_voidDisableGlobalInterrupt()
{
	CLR_BIT(SREG,7);


}
