#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP
#include "Command.hpp"

class CursorHome: public Command
{
public:
    CursorHome()
        : col{0}
    {
    } 
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int col;
};

#endif