#include "TaskBase.h"

void TaskBase::createTask(size_t stackSize, uint32_t priority) {
    /* already running */
    if (this->isRunning) return;

    this->isRunning = true;
    xTaskCreate(
        [](void* pvParameter){
            TaskBase* this_ptr = static_cast<TaskBase*>(pvParameter);
            this_ptr->taskMain();
        },
        this->getName(),
        stackSize,
        this,
        priority,
        &this->taskHandle
    );
}

void TaskBase::deleteTask(void) {
    /* task is not running */
    if (!this->isRunning) return;

    this->isRunning = false;
    vTaskDelete(this->taskHandle);
}

void TaskBase::taskMain(void) {
    setup();
    while(true) {
        loop();
    }
}
