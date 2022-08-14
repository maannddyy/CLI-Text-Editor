#include "InsertChar.hpp"

void InsertChar::execute(EditorModel& model)
{
    model.insertCharacter(character);
}

void InsertChar::undo(EditorModel& model)
{
    model.backspace();
}