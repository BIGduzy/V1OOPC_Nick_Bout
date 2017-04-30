#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "iostream"
/**
 * @file
 * @brief
 * 2D interger vector ADT
 * @details
 * This is 2D vector ADT that stores its two components as (signed) integers.
 * The x and y components are public attributes.
 * The appropriate constructors and operators are provided.
*/
class Vector {
public:
    int x, y;
    
    /**
     * @brief
     * Default constructor
     * @details
     * This constructor initializes the x and y attributes with 0.
    */
    Vector();

    /**
     * @brief
     * Default constructor
     * @details
     * This constructor does initialize the x and y attributes.
    */
    Vector(int x, int y);
    
    /**
     * @brief
     * compare two Vectors
     * @details
     * This operator tests for equality. It returns true
     * if and only if the x and y values of both
     * operands are equal.
     */
    bool operator==(const Vector& rhs) const;

    /**
     * @brief
     * Unary plus operator
     * @details
     * Returns a copy of the Vector 
     */
    Vector operator+() const;
    
    /**
     * @brief
     * Add a Vector to a Vector
     * @details
     * This operator+ adds a Vector to a Vector. 
     */
    Vector operator+(const Vector& rhs) const;
    
    /**
     * @brief
     * Add a Vector to a Vector
     * @details
     * This operator+ adds a Vector to a Vector. 
     */
    Vector& operator+=(const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    Vector operator*(const int& rhs) const;
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    friend Vector operator*(const int& lhs, const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by Vector
     * @details
     * This operator* multiplies a Vector by a Vector.
     */
    Vector& operator*=(const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by interger
     * @details
     * This operator* multiplies a Vector by a interger value.
     */
    Vector& operator*=(const int& rhs);
    
    friend std::ostream& operator<<(std::ostream& lhs, const Vector& rhs);
};



#endif // VECTOR_HPP
