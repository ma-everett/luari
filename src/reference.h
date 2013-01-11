

#ifndef grt_ri_reference_h
#define grt_ri_reference_h 1

#include "memory.h"

namespace grt
{
  class ReferenceCounted
    {
    public:

      ReferenceCounted( )
	{
	  _refs = 0;
	}

      ~ReferenceCounted( ) { }

      unsigned int get_count( void ) const
	{
	  return _refs;
	}

      inline unsigned int
	link( void )
	{
	  _refs++;
	  return _refs;
	}

      inline unsigned int
	ulink( void )
	{
	  _refs--;
	  return _refs;
	}

    protected:

      unsigned int _refs;
    };

  template<class T>
    class Reference
    {
    public:

      Reference( T * t = NULL )
	{
	  _target = t;
	  if (_target) _target->link( );
	}

      Reference( const Reference<T> & rh )
	{
	  _target = rh._target;
	  if (_target) _target->link( );
	}

      ~Reference( )
	{
	  _ulink( );
	}

      Reference & operator= ( const Reference<T> & rh )
	{
	  if (rh._target) rh._target->link( );
	  _ulink( );
	  _target = rh._target;

	  return (*this);
	}

      Reference & operator= ( T * t )
	{
	  _ulink( );
	  _target = t;
	  if (_target) _target->link( );

	  return (*this);
	}

      T * operator->( ) { return _target; }
      const T * operator->( ) const { _target; }
      operator bool( ) const { return _target != NULL; }

      T * ptr( void )
	{
	  return _target;
	}

      T & ref( void )
	{
	  return _target;
	}

    private:

      inline 
	void _ulink( void )
	{
	  if (_target && _target->ulink( ) == 0)
	    delete _target;
	}

      T * _target;
    };

}

#endif
	
