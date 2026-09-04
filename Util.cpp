#include "Util.h"

FVector2D::FVector2D(int inX, int inY)
{
    X = inX;
    Y = inY;
}

FVector2D::FVector2D(FVector2D* RHS)
{
    X = RHS->X;
    Y = RHS->Y;
}

FVector2D FVector2D::operator+(const FVector2D& RHS) const
{
    return FVector2D(X+RHS.X,Y+RHS.Y);
}
