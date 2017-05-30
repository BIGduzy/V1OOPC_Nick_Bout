#pragma once

/**
 * @file
 * @brief
 * 2D interger vector ADT
 * @details
 * This is 2D vector ADT that stores its two components as (signed) integers.
 * The x and y components are public attributes.
 * The appropriate constructors and operators are provided.
*/
class Vector2d {
public:
    int x, y;

    /**
     * @brief
     * Default constructor
     * @details
     * This constructor does initialize the x and y attributes.
    */
    Vector2d(int x, int y);
    
    /**
     * @brief
     * compare two Vectors
     * @details
     * This operator tests for equality. It returns true
     * if and only if the x and y values of both
     * operands are equal.
     */
    bool operator==(const Vector2d& rhs) const;

    /**
     * @brief
     * Unary plus operator
     * @details
     * Returns a copy of the Vector 
     */
    Vector2d operator+() const;
    
    /**
     * @brief
     * Add a Vector to a Vector
     * @details
     * This operator+ adds a Vector to a Vector. 
     */
    Vector2d operator+(const Vector2d& rhs) const;
    
    /**
     * @brief
     * Add a Vector to a Vector
     * @details
     * This operator+ adds a Vector to a Vector. 
     */
    Vector2d& operator+=(const Vector2d& rhs);
    
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    Vector2d operator*(const int& rhs) const;
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    friend Vector2d operator*(const int& lhs, const Vector2d& rhs);
    
    /**
     * @brief
     * Multiply a Vector by Vector
     * @details
     * This operator* multiplies a Vector by a Vector.
     */
    Vector2d& operator*=(const Vector2d& rhs);
    
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    Vector2d& operator*=(const int& rhs);
};

