#pragma once

/* ================================================
*  Base (abstract) move class
================================================ */
class MoveType {

public:
    MoveType() {}
    virtual ~MoveType() = default;
    virtual void Move() = 0;
};

//
// Base (abstract) move class
//
class BasicPlayerMovement : public MoveType {

public:
    BasicPlayerMovement() : MoveType() { }
    virtual void Move() { }

};
