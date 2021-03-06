// Filename: Array.cpp
#include "Array.h"

// This must be defined for inttypes.h to define the fixed with integer macros
#if defined(__cplusplus) && !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS
#endif
#include <inttypes.h> // UINT64_MAX
namespace bamboo   // open namespace
{


// type constructor
Array::Array(Type *element_type, const NumericRange& size) :
    m_element_type(element_type), m_array_range(size)
{
    if(m_element_type == nullptr) {
        m_element_type = Type::invalid;
    }

    // TODO: Handle non-uinteger NumericRanges
    if(m_array_range.is_empty()) {
        m_array_size = 0;
        m_array_range.min.uinteger = 0;
        m_array_range.max.uinteger = UINT64_MAX;
    } else if(m_array_range.min == m_array_range.max) {
        m_array_size = (unsigned int)m_array_range.min.uinteger;
    } else {
        m_array_size = 0;
    }

    if(m_element_type->has_fixed_size() && m_array_size > 0) {
        m_subtype = kTypeArray;
        m_size = m_array_size * m_element_type->fixed_size();
    } else {
        m_subtype = kTypeVararray;
        m_size = 0;
    }



    if(m_element_type->subtype() == kTypeChar) {
        if(m_subtype == kTypeArray) {
            m_subtype = kTypeString;
        } else {
            m_subtype = kTypeVarstring;
        }
    } else if(m_element_type->subtype() == kTypeUint8) {
        if(m_subtype == kTypeArray) {
            m_subtype = kTypeBlob;
        } else {
            m_subtype = kTypeVarblob;
        }
    }
}

// as_array returns this as an Array if it is an array, or nullptr otherwise.
Array *Array::as_array()
{
    return this;
}
const Array *Array::as_array() const
{
    return this;
}


} // close namespace bamboo
