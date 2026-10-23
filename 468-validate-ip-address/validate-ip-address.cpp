class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.empty())
            return "Neither";
        bool ip4=false, ip6 = false;

        for (char c : queryIP) {
            if (c == '.') {
                ip4 = true;
                break;
            }
            if (c == ':') {
                ip6 = true;
                break;
            }
        }

        if (ip4) {
            if (!isdigit(queryIP[queryIP.size() - 1]))
                return "Neither";
            stringstream ss(queryIP);
            string token;
            int cnt = 0;
            while (getline(ss, token, '.')) {
                if (token.empty())
                    return "Neither";

                if (!regex_match(token, regex("[0-9]+")))
                    return "Neither";

                if (token.size() > 1 && token[0] == '0')
                    return "Neither";

                if (token.size() > 3)
                    return "Neither";

                if (stoi(token) > 255)
                    return "Neither";

                cnt++;
            }
            if (cnt == 4)
                return "IPv4";
            return "Neither";
        }

        if (ip6) {
            if (!isdigit(queryIP[queryIP.size() - 1]) &&
                !isalpha(queryIP[queryIP.size() - 1]))
                return "Neither";

            stringstream ss(queryIP);
            string token;
            int cnt = 0;
            while (getline(ss, token, ':')) {
                if (!regex_match(token, regex("[0-9a-fA-F]+")))
                    return "Neither";
                if (token.size() < 1 || token.size() > 4)
                    return "Neither";
                cnt++;
            }
            if (cnt == 8)
                return "IPv6";
            return "Neither";
        }
        return "Neither";
    }
};