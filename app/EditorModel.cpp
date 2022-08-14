// EditorModel.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
//#include "RightCursor.hpp"



EditorModel::EditorModel()
    : colNum{1}, rowNum{1}, numLines{1}, currError{""}, prevCol{1}
{
    text.push_back("");
}


int EditorModel::cursorLine() const
{
    return rowNum;
}


int EditorModel::cursorColumn() const
{
    return colNum;
}


int EditorModel::lineCount() const
{
    return numLines;
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return currError;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    currError = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    currError = "";
}

void EditorModel::moveRight()
{
    if (colNum >= text[rowNum-1].size() + 1 && rowNum >= numLines)
    {
        EditorException err{"Already at end"};
        setErrorMessage(err.getReason());
        throw err;
    }
    else if (colNum == text[rowNum-1].size()+1)
    {
        colNum = 1;
        rowNum++;
    }
    else
    {
        colNum++;
        clearErrorMessage();
    }
}

void EditorModel::moveLeft()
{
    if (colNum == 1 && rowNum == 1)
    {
        EditorException err{"Already at beginning"};
        setErrorMessage(err.getReason());
        throw err;
    }
    else if (colNum == 1)
    {
        rowNum--;
        colNum = text[rowNum-1].size() + 1;
    }
    else
    {
        colNum--;
        clearErrorMessage();
    }
}

void EditorModel::insertCharacter(char c)
{
    if (text.size() < numLines - 1)
    {
        text.push_back("");
    }
    text[rowNum - 1].insert(text[rowNum-1].begin() + colNum - 1, c);
    colNum++;
}

char EditorModel::backspace()
{
    if (colNum == 1 && rowNum == 1)   
    {
        EditorException err{"Already at beginning"};
        setErrorMessage(err.getReason());
        throw err;
    }

    else
    {
        char lastChar = text[rowNum-1][colNum-2];
        text[rowNum-1].erase(text[rowNum-1].begin() + colNum - 2);
        colNum--;
        clearErrorMessage();
        return lastChar;
    }
    
}

void EditorModel::moveUp()
{
    if (rowNum == 1)
    {
        EditorException err{"Already at top"};
        setErrorMessage(err.getReason());
        throw err;
    }
    else
    {
        if (text[rowNum-2].size() < colNum)
        {
            colNum = text[rowNum-2].size() + 1;
        }
        rowNum--;
        clearErrorMessage();
    }
}

void EditorModel::moveDown()
{
    if (numLines <= rowNum)
    {
        EditorException err{"Already at bottom"};
        setErrorMessage(err.getReason());
        throw err;
    }
    else
    {
        if (text[rowNum].size() < colNum)
        {
            colNum = text[rowNum].size() + 1;
        }
        rowNum++;
        clearErrorMessage();
    }
}

std::string EditorModel::newLine()
{
    std::string previous = text[rowNum-1].substr(colNum-1, text[rowNum-1].size()-colNum + 1);
    text[rowNum-1].erase(colNum-1, text[rowNum-1].size()-colNum + 1);
    text.insert(text.begin()+ rowNum, previous);
    numLines++;
    rowNum++;
    colNum = 1;
    return previous;
}

void EditorModel::undoNewLine(std::string s)
{
    colNum = text[rowNum-2].size() + 1;
    text[rowNum-2].append(s);
    text.pop_back();
    numLines--;
    rowNum--;
    
}

unsigned int EditorModel::cursorHome()
{
    unsigned int currColNum = colNum;
    colNum = 1;
    return currColNum;
}

void EditorModel::undoCursorHome(unsigned int n)
{
    colNum = n;
}

unsigned int EditorModel::cursorEnd()
{
    unsigned int currColNum = colNum;
    colNum = text[rowNum-1].size() + 1;
    return currColNum;
}

void EditorModel::undoCursorEnd(unsigned int n)
{
    colNum = n;
}

std::string EditorModel::deleteLine()
{
    prevCol = colNum;
    std::string deletedString = text[rowNum-1];
    if (numLines == 1)
    {
        text[0] = "";
        colNum = 1;
    }
    else
    {
        text.erase(text.begin() + rowNum - 1);
        numLines--;
        if (rowNum > numLines)
        {
            rowNum--;
        }
        if (colNum > text[rowNum-1].size()+1)
        {
            colNum = text[rowNum-1].size() + 1;
        }
        
    }
    return deletedString;
}

void EditorModel::undoDeleteLine(std::string s)
{
    numLines++;
    text.insert(text.begin() + rowNum - 1, s);
    colNum = prevCol;

}