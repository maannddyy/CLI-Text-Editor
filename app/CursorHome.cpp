#include "CursorHome.hpp"

void CursorHome::execute(EditorModel& model) 
{
    col = model.cursorHome();
}

void CursorHome::undo(EditorModel& model)
{
    model.undoCursorHome(col);
}