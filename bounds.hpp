#ifndef BOUNDS
#define BOUNDS

#include <cstddef>
#include <vector>
using namespace std;
template<typename T>
std::size_t my_lower_bound(const std::vector<T> &a, const T &x) {
  (void)x;
  size_t l=0;
  size_t r=a.size();
  while(l<r){
	  size_t p=(l+r)/2;
	  if(a[p]<x)
		  l=p+1;
	  else
		  r=p;}
  return l;}

template<typename T>
std::size_t my_upper_bound(const std::vector<T> &a, const T &x) {
  (void)x;
  size_t l=0;
  size_t r=a.size();
  while(l<r){
	  size_t p=(l+r)/2;
	  if(a[p]<=x)
		  l=p+1;
	  else
		  r=p;}
  return l;}
		
#endif
