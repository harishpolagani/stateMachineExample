#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef enum state{
unknownState,
idleState,
cardInsertedState,
pinEnteredState,
optionSelectedState,
amountEnteredState,
maxState
}eState;

typedef enum event{
unknownEvent,
cardInsertedEvent,
pinEnteredEvent,
optionSelectedEvent,
amountEnteredEvent,
moneyDispatchEvent,
maxEvent
}eEvent;

typedef eState (*eventHandler)();

//function declarations
eState cardInsertedEventHandler();
eState pinEnteredEventHandler();
eState optionSelectedEventHandler();
eState amountEnteredEventHandler();
eState moneyDispatchEventHandler();
eEvent readEvent();


typedef struct sm{
eState state;
eEvent event;
eventHandler handler;
}sMachine;

sMachine stateMachine[]={
{unknownState,unknownEvent,NULL},
{idleState,cardInsertedEvent,cardInsertedEventHandler},
{cardInsertedState,pinEnteredEvent,pinEnteredEventHandler},
{pinEnteredState,optionSelectedEvent,optionSelectedEventHandler},
{optionSelectedState,amountEnteredEvent,amountEnteredEventHandler},
{amountEnteredState,moneyDispatchEvent,moneyDispatchEventHandler}
};

int main()
{

eState currentState = unknownState;
eState nextState = unknownState;
eEvent currentEvent = unknownEvent;


while(1){
    
    printf("current event =%d, current state= %d  \n ",currentEvent,currentState);
    currentEvent = readEvent();
    if( currentEvent >  unknownEvent && currentEvent <= moneyDispatchEvent )
    {
    currentState = (*stateMachine[currentEvent].handler)();
    }
    
}

return 0;
}


//function declarations
eState cardInsertedEventHandler()
{
 return cardInsertedState;
}
eState pinEnteredEventHandler()
{
return pinEnteredState;
}
eState optionSelectedEventHandler()
{
return optionSelectedState;
}

eState amountEnteredEventHandler()
{
return amountEnteredState;
}
eState moneyDispatchEventHandler()
{
return idleState;
}

eEvent readEvent()
{
int choice=0;
printf(" \n 1. insert card \n 2. enter pin \n 3. select options \n 4. enter amount \n 5. dispatch money:\n");

scanf("%d",&choice);

switch(choice)
{
case 1: return cardInsertedEvent;
        break;
case 2: return pinEnteredEvent;
        break;
case 3: return optionSelectedEvent;
        break;
case 4: return amountEnteredEvent;
        break;
case 5: return moneyDispatchEvent;
        break;
default: printf("\noopos! wrong inPut \n please enter proper value \n");
}
 return unknownEvent;
}


