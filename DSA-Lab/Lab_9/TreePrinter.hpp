#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Renders any binary tree whose nodes have `data`, `left` and `right`.
template <typename NodeT>
class TreePrinter
{
public:
    static void print(const NodeT *root, std::ostream &out = std::cout)
    {
        if (!root)
        {
            out << "(empty tree)\n";
            return;
        }

        Block b = build(root);
        for (const auto &line : b.lines)
        {
            out << line << '\n';
        }
    }

private:
    struct Block
    {
        std::vector<std::string> lines;
        int width = 0;
        int root = 0;
    };

    static void put(std::string &line, int pos, const std::string &s)
    {
        if ((int)line.size() < pos + (int)s.size())
        {
            line.resize(pos + s.size(), ' ');
        }
        line.replace(pos, s.size(), s);
    }

    static Block build(const NodeT *n)
    {
        Block b;
        if (!n)
        {
            return b;
        }

        std::string s = std::to_string(n->data);
        int len = (int)s.size();

        if (!n->left && !n->right)
        {
            b.lines = {s};
            b.width = len;
            b.root = len / 2;
            return b;
        }

        Block L = build(n->left), R = build(n->right);
        std::string top, mid;
        int rOff = 0, start;

        if (n->left && n->right)
        {
            int lr = L.root;
            int gap = std::max(1, len + 3 - (L.width - L.root) - R.root);
            rOff = L.width + gap;
            int rr = rOff + R.root;
            start = (lr + rr + 1) / 2 - len / 2;
            put(top, lr + 1, std::string(rr - lr - 1, '_'));
            put(top, start, s);
            put(mid, lr, "/");
            put(mid, rr, "\\");
        }
        else if (n->left)
        {
            start = L.root + 2;
            put(top, L.root + 1, "_");
            put(top, start, s);
            put(mid, L.root, "/");
        }
        else
        {
            rOff = std::max(0, len + 2 - R.root);
            int rr = rOff + R.root;
            start = 0;
            put(top, 0, s);
            put(top, len, std::string(rr - len, '_'));
            put(mid, rr, "\\");
        }

        b.root = start + len / 2;
        b.width = std::max({L.width, rOff + R.width, start + len});
        b.lines.push_back(top);
        b.lines.push_back(mid);

        size_t rows = std::max(L.lines.size(), R.lines.size());
        for (size_t i = 0; i < rows; ++i)
        {
            std::string row;
            if (i < L.lines.size())
            {
                put(row, 0, L.lines[i]);
            }
            if (i < R.lines.size())
            {
                put(row, rOff, R.lines[i]);
            }
            b.lines.push_back(row);
        }
        return b;
    }
};