#include "UpCursor.hpp"


void UpCursor::execute(EditorModel& model) 
{
    model.moveUp();
}

void UpCursor::undo(EditorModel& model)
{
    model.moveDown();
}