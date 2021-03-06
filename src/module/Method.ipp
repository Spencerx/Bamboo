// Filename: Method.ipp
namespace bamboo { // open namespace


// num_parameters returns the number of parameters/arguments of the method.
inline size_t Method::num_parameters() const {
    return m_parameters.size();
}
// get_element returns the <n>th parameter of the method.
inline Parameter *Method::get_parameter(unsigned int n) {
    return m_parameters.at(n).get();
}
inline const Parameter *Method::get_parameter(unsigned int n) const {
    return m_parameters.at(n).get();
}
// parameter_by_name returns the parameter with <name>, or nullptr if no such param exists.
inline Parameter *Method::parameter_by_name(const std::string& name) {
    auto it = m_parameters_by_name.find(name);
    if(it == m_parameters_by_name.end()) {
        return nullptr;
    }
    return it->second;
}
inline const Parameter *Method::parameter_by_name(const std::string& name) const {
    auto it = m_parameters_by_name.find(name);
    if(it == m_parameters_by_name.end()) {
        return nullptr;
    }
    return it->second;
}


} // close namespace bamboo
