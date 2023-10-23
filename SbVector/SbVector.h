//
//  SbVector.h
//  ClassesReview
//
//  Created by Sapient Bits on 22/10/2023.
//

#ifndef SbVector_h
#define SbVector_h

class SbVector
{
private:
    int elements;
    int currSize;
    int* arr;
public:
    SbVector();
    explicit SbVector(std::initializer_list<int> list);
    SbVector(const SbVector& v);
    SbVector& operator=(const SbVector& rhs);
    void insert(const int num);
    bool remove(const int num);
    bool search(const int num) const;
    int& operator[](const size_t index);
    const int& operator[](const size_t index) const;
    int numberOfElements() const { return elements; }
    ~SbVector();
};
SbVector::SbVector() : elements{0}, currSize{5}
{
    arr = new int[currSize];
}
SbVector::SbVector(std::initializer_list<int> list)
{
    elements = (int) list.size();
    currSize =  (5 > elements) ? 5 : elements*2;
    arr = new int [currSize];
    int i=0;
    for (auto num : list)
    {
        arr[i] = num;
        i++;
    }
}
SbVector::SbVector(const SbVector&v)
{
    elements = v.elements;
    currSize = v.currSize;
    arr = new int[currSize];
    for(int i=0; i<elements; i++)
    {
        arr[i] = v.arr[i];
    }
}
SbVector& SbVector::operator=(const SbVector &rhs)
{
    if(this != &rhs)
    {
        delete [] arr;
        elements = rhs.elements;
        currSize = rhs.currSize;
        arr = new int[currSize];
        for(int i=0; i<elements; i++)
        {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
}
void SbVector::insert(const int num)
{
    if(elements==currSize)
    {
        currSize += 10;
        int* temp = new int [currSize];
        for(int i=0; i<elements; i++)
        {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }
    arr[elements]=num;
    elements++;
}
bool SbVector::remove(const int num)
{
    int index=0;
    bool removed=false;
    while(index<elements)
    {
        if(arr[index] == num)
        {
            while (index < elements-1)
            {
                arr[index] = arr [index+1];
                index++;
            }
            elements--;
            removed=true;
        }
        index++;
    }
    return removed;
    
}
bool SbVector::search(const int num) const
{
    bool found = false;
    int i=0;
    while(!found && i<elements)
    {
        if (arr[i] == num)
        {
            found = true;
        }
        i++;
    }
    return found;
}
int& SbVector::operator[](const size_t index)
{
    if (index>=elements)
    {
        throw std::out_of_range("Index out of bound");
    }
    return arr[index];
}
const int& SbVector::operator[](const size_t index) const
{
    if (index>=elements)
    {
        throw std::out_of_range("Index out of bound");
    }
    return arr[index];
}
std::ostream& operator<<(std::ostream& os, const SbVector& v)
{
    for(int i=0; i<v.numberOfElements(); i++)
    {
        std::cout<<v[i]<<" ";
    }
    return os;
}
SbVector::~SbVector()
{
    delete [] arr;
}

#endif /* SbVector_h */
