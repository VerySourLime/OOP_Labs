#pragma once

const int EvNothing = 0;
const int EvMessage = 100;
const int CmCreateGroup = 1;
const int CmAddToGroup = 2;
const int CmRemoveFromGroup = 3;
const int CmShow = 4; 
const int CmShowName = 5;
const int CmExit = 6;

struct TEvent
{
    int what;
    union
    {
        int command;
        struct
        {
            int message;
            int settings;
        };
    };
};
