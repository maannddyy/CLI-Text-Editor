#include "RightCursor.hpp"


void RightCursor::execute(EditorModel& model) 
{
    model.moveRight();
}

void RightCursor::undo(EditorModel& model)
{
    model.moveLeft();
}