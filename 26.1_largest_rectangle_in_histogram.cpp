class Solution {
private:
  void prevSmallest(vector<int> heights, vector<int>& prev) {
    int n = heights.size();
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++) {
      // we need element which is smaller than
      // or equal to the current element
      while (st.top() != -1 && heights[st.top()] >= heights[i]) {
        // found greater or equal element, so go deep
        // in case -1 found loop will break
        // and -1 will be considered as top
        st.pop();
      }
      int top = st.top();
      prev[i] = top;

      st.push(i);
    }
  }

  void nextSmallest(vector<int> heights, vector<int>& next) {
    int n = heights.size();
    stack<int> st;
    st.push(n);

    for (int i = n - 1; i >= 0; i--) {
      // we need element which is smaller than
      // or equal to the current element
      while (st.top() != n && heights[st.top()] >= heights[i]) {
        // found greater or equal element, so go deep
        // in case -1 found loop will break
        // and -1 will be considered as top
        st.pop();
      }
      int top = st.top();
      next[i] = top;

      st.push(i);
    }
  }

public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = -1;
    vector<int> prev(n), next(n);

    prevSmallest(heights, prev);
    nextSmallest(heights, next);

    for (int i = 0; i < heights.size(); i++) {
      int w = next[i] - prev[i] - 1;
      int h = heights[i];

      int area = w * h;
      ans = max(ans, area);
    }
    return ans;
  }
};
