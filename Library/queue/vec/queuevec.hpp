
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

#include "../queue.hpp"
#include "../../vector/vector.hpp"
#include <cstdlib>

namespace lasd
{

  template <typename Data>
  class QueueVec : public virtual Queue<Data>, protected virtual Vector<Data>
  {

  private:
    // ...

  protected:
    using Vector<Data>::Elements;
    using LinearContainer<Data>::size;
    long front = -1;
    long rear = -1;

  public:
    // Default constructor
    QueueVec() = default;

    // Specific constructor
    QueueVec(const LinearContainer<Data> &); // A queue obtained from a LinearContainer

    // Copy constructor
    QueueVec(const QueueVec &);

    // Move constructor
    QueueVec(QueueVec &&) noexcept;

    // Destructor
    virtual ~QueueVec() = default;

    // Copy assignment
    QueueVec &operator=(const QueueVec &);

    // Move assignment
    QueueVec &operator=(QueueVec &&) noexcept;

    // Comparison operators
    bool operator==(const QueueVec &) const noexcept;
    inline bool operator!=(const QueueVec &) const noexcept;

    // Specific member functions (inherited from Queue)

    void Enqueue(const Data &) override;     // Override Queue member (copy of the value)
    void Enqueue(Data &&) noexcept override; // Override Queue member (move of the value)
    Data &Head() const override;             // Override Queue member (must throw std::length_error when empty)
    void Dequeue() override;                 // Override Queue member (must throw std::length_error when empty)
    Data HeadNDequeue() override;            // Override Queue member (must throw std::length_error when empty)

    // Specific member functions (inherited from Container)

    inline bool Empty() const noexcept override; // Override Container member
    inline bool Full() const noexcept;

    ulong Size() const noexcept override; // Override Container member

    void Clear() override; // Override Container member

  protected:
    // Auxiliary member functions
    void Resize(const ulong &);
  };

}

#include "queuevec.cpp"

#endif
