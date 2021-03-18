#ifndef VECTOR_H
#define VECTOR_H

#include<vector>
    /**
     * @class Vector
     * @brief Creates a Vector template
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 01
     * @date 18/04/2020 Victor Kavassaki Pimentel, Started
     *
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 02
     * @date 25/04/2020 Victor Kavassaki Pimentel, Added a copy constructor and edited pushIn function
     *
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 03
     * @date 10/06/2020 Victor Kavassaki Pimentel, Encapsulated STL Vector
     *
     *
     */

using namespace std;


template <typename T>
class Vector
{
    public:
    /**
     * @brief Constructs the Vector
     *
     */
        Vector();
    /**
     * @brief Copy constructor
     *
     */
        Vector(T& object2);
    /**
     * @brief deconstructs the vector
     *
     */
        ~Vector();
    /**
     * @brief Insert an object in the vector
     * @param object - object to be inserted in the end of the vector
     * @return void
     */
        void pushIn(const T& object);

    /**
     * @brief Overloads the [] operator
     * @param index - index of the object in the vector to be returned
     * @return T&
     */
        T& operator[](unsigned index);

    /**
     * @brief Overloads the [] operator
     * @param index - index of the object in the vector to be returned
     * Nothing can be modified here since it is const
     * @return T&
     */
       const T& operator[](unsigned index) const;

    /**
     * @brief Returns the length of the vector
     * Nothing can be modified in tis function since it is const
     * @return int
     */
        int GetLength() const;

     /**
     * @brief clears the vector
     * @return void
     */
        void deleteVec();
    private:

        vector<T> array; //Vector of type T
};

template <typename T>
Vector<T>::Vector(){
    vector<T> array;
}


template <typename T>
Vector<T>::~Vector(){
    array.clear();
}

template <typename T>
void Vector<T>::pushIn(const T& object){
    array.push_back(object);
}


template <typename T>
T& Vector<T>::operator[](unsigned index){
    return array.at(index);
}

template <typename T>
const T& Vector<T>::operator[](unsigned index) const{
    return array.at(index);
}

template <typename T>
int Vector<T>::GetLength() const{

    return array.size();
}

template <typename T>
void Vector<T>::deleteVec(){
    array.clear();
}

#endif
