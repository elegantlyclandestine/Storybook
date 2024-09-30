#pragma once
#ifndef storybook_h
#define storybook_h

#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <unordered_map>

struct Storybook {
    struct Branch {
        std::string originating_node;
        bool is_important;
    };

    struct Choice {
        std::vector<std::string> choice;
        bool will_branch_out;
        bool will_shift_story;
    };

    struct Node {
        Branch branch;
        std::vector<std::string> dialogue;
        std::vector<Choice> choices;
        bool is_ending;
    };

    struct Character {
        struct Playable {
            std::string name;
            std::string avatar_link;
            int player_index;
        };
        struct Supporting {
            std::string name;
            std::string avatar_link;
        };
    };

    struct Narrative {
        std::vector<Character> cast;
        std::unordered_map<Branch, std::vector<Node>> narrative_tree;
    };

    struct Story {
        std::string title;
        dpp::snowflake author;
        char content_rating;
        std::string description;
        int times_played;
        int min_players;
        int max_players;
        Narrative narrative;
    };
};

#endif
