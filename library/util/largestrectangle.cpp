template <typename T>
lint largest_rectangle(vector<T> height) {
    vector<int> st;
    height.push_back(0);
    int n = height.size();
    vector<int> left(n);
    lint ret = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.back()] >= height[i]) {
            ret = max(ret, (lint)(i - left[st.back()] - 1) * height[st.back()]);
            st.pop_back();
        }
        left[i] = st.empty() ? -1 : st.back();
        st.emplace_back(i);
    }
    return ret;
}