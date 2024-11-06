#pragma once
#include "Dialog.h"

Dialog::Dialog() : Vector()
{
    this->EndState = 0;
}

void Dialog::GetEvent(TEvent &event)
{
    cout << "Choose action\n"
         << "m: Create grop (example: m10)\n"
         << "+: Add element in group\n"
         << "-: Delete element from group\n"
         << "s: Output information about group elements\n"
         << "z: Output information about names of group elements\n"
         << "q: End of work\n";
    cout << "-> ";
    string temp_command, temp_params;
    cin >> temp_command;
    char code = temp_command[0];
    if (is_command(code))
    {
        event.what = EvMessage;
        switch (code)
        {
        case 'm':
            event.command = CmCreateGroup;
            break;
        case '+':
            event.command = CmAddToGroup;
            break;
        case '-':
            event.command = CmRemoveFromGroup;
            break;
        case 's':
            event.command = CmShow;
            break;
        case 'z':
            event.command = CmShowName;
            break;
        case 'q':
            event.command = CmExit;
            break;
        }
        if (temp_command.size() > 1)
        {
            temp_params = temp_command.substr(1, temp_command.size() - 1);
            int settings = atoi(temp_params.c_str());
            event.settings = settings;
        }
    }
    else
    {
        event.what = EvNothing;
    }
}

bool Dialog::is_command(char action)
{
    int i = 0;
    string temp_command = "m+-szq";
    while (i < int(temp_command.size()))
    {
        if (action == temp_command[i])
        {
            return true;
        }
        i++;
    }
    return false;
}

int Dialog::Execute()
{
    TEvent event;
    do
    {
        EndState = 0;
        GetEvent(event);
        cout << "\n";
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}

void Dialog::HandleEvent(TEvent &event)
{
    if (event.what == EvNothing)
    {
        cout << "Invalid command.\n";
        return;
    }
    switch (event.command)
    {
    case CmCreateGroup:
        create(event.settings);
        ClearEvent(event);
        break;
    case CmAddToGroup:
        Add();
        ClearEvent(event);
        break;
    case CmRemoveFromGroup:
        Del();
        ClearEvent(event);
        break;
    case CmShow:
        print(false);
        ClearEvent(event);
        break;
    case CmShowName:
        print(true);
        ClearEvent(event);
        break;
    case CmExit:
        EndExec();
        ClearEvent(event);
        break;
    default:
        break;
    }
}

void Dialog::ClearEvent(TEvent &event)
{
    event.what = EvNothing;
}

int Dialog::Valid()
{
    if (EndState == 0)
    {
        return 0;
    }
    return 1;
}

void Dialog::EndExec()
{
    EndState = 1;
}
