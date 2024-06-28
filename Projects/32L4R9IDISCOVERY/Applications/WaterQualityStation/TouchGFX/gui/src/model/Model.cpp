#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <cmsis_os2.h>
#include "main.h"
extern "C"
{
    extern osMessageQueueId_t adcQueueHandle;
}
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR
	//Get Data from ADC Queue
	if (osMessageQueueGet(adcQueueHandle, &ADC_value, 0U, 0) == osOK)
	{
		modelListener->setADC(ADC_value);  // send data to presenter
	}
#endif
}
