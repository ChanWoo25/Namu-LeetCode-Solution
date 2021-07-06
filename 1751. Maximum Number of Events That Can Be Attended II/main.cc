#include "../libs.hpp"


using Event = std::vector<int>;

inline int FirstDay(const Event& event) {
  return event[0];
}

inline int LastDay(const Event& event) {
  return event[1];
}

inline int EventValue(const Event& event) {
  return event[2];
}

class Solution {
  public:
    int maxValue(std::vector<Event>& events, int k_max_visits) {
      std::sort(events.begin(), events.end(),
        [] (const Event& first, const Event& second) -> bool {
          return LastDay(first) < LastDay(second);
        });

      const int event_count = events.size();

      std::vector<std::vector<int>> dp(event_count + 1, std::vector<int>(k_max_visits + 1));
      
      for (int event_id = 0; event_id < event_count; ++event_id) {
        const auto event = events[event_id];

        // O(log events.length)  // AC 100 ms
        auto it = std::lower_bound(std::next(events.rbegin(), event_count - event_id), events.rend(), event,
          [] (const Event& event, const Event& to_find) -> bool {
            return LastDay(event) >= FirstDay(to_find);
          });
        auto prev_event_id = event_count - std::distance(events.rbegin(), it);


        for (int visits = 1; visits <= k_max_visits; ++visits) {

          dp[event_id + 1][visits] = std::max(dp[event_id][visits],
            EventValue(event) + dp[prev_event_id][visits - 1]);
        }
      }

      return *std::max_element(dp[event_count].begin(), dp[event_count].end());
    }
};

int main()
{

    Solution S;
    vector<vector<int>> num = {{1,2,4},{3,4,3},{2,3,1}};
    cout << S.maxValue(num, 2);

    return 0;
}