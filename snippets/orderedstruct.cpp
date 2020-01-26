struct ${1:name} {
    int ${2:a}, ${3:b};
    bool operator<(const ${1:name} &rhs) const { return ${2:a} < rhs.${2:a}; };
};