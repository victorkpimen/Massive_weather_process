#include <iostream>

#include "Vector.h"
#include "BST.h"

    /**
     * @class Collect
     * @brief Collector class used to collect data from a BST
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 01
     * @date 10/06/2020 Victor Kavassaki Pimentel, Started
     *
     */

template <class T>
using Bst = BST<T>;

using namespace std;

template <class T>
class CollectU
{

public:

    /**
     * @brief collects items into a vector
     * @param data - object to be inserted in the end of the vector
     * @return void (static)
     */
    static void vecCollect(const T& data)
    {
       weatherVec.pushIn(data);
    }

    /**
     * @brief returns the size of the vector
     * @return int
     */
    int size()
    {
        return weatherVec.GetLength();
    }

    /**
     * @brief [] operator which returns the vector data in a specific index
     * @param k - index of a vector
     * @return T&
     */
    T& operator[](int k)
    {
        return weatherVec[k];   // used to return the data that has been collected.
    }

    /**
     * @brief clears the vector
     * @return void (static)
     */
    static void deleteData()
    {
        weatherVec.deleteVec();
    }


private:
    static Vector<T> weatherVec;  // static vector which will hold the data from a BST
};

template <class T>
Vector<T> CollectU<T>::weatherVec;

