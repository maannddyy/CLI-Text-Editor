#include "LeftCursor.hpp"


void LeftCursor::execute(EditorModel& model) 
{
    model.moveLeft();
}

void LeftCursor::undo(EditorModel& model)
{
    model.moveRight();
}