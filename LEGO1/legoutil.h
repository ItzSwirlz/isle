#ifndef LEGOUTIL_H
#define LEGOUTIL_H

template <class T>
inline T Abs(T p_t)
{
  return p_t < 0 ? -p_t : p_t;
}

// this should not be used with floats unless you
// are a fan of signed zeroes
template <class T>
inline T AbsQuirk(T p_t)
{
  return p_t <= 0 ? -p_t : p_t;
}

template <class T>
inline T Align(T value, T align_to)
{
  return (value + (align_to - 1)) & ~(align_to - 1);
}

template <class T>
inline T Min(T p_t1, T p_t2)
{
  return p_t1 < p_t2 ? p_t1 : p_t2;
}

template <class T>
inline T Max(T p_t1, T p_t2)
{
  return p_t1 > p_t2 ? p_t1 : p_t2;
}

void ConvertHSVToRGB(float r, float g, float b, float* out_r, float* out_g, float* out_b);

#endif // LEGOUTIL_H
