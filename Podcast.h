//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_PODCAST_H
#define CIRCULARTEMPLATEDLIST_PODCAST_H

#include <iostream>
#include "Media.h"

class Podcast : public Media {
private:
    std::string episodeTitle;
    std::string host;
    int episodeNumber;
public:
    Podcast(const std::string& t, const std::string& h, int d)
        : Media(t, d), episodeTitle(t), host(h), episodeNumber(d) {}

    std::string toString() const override;
    void play() const override;
};

#endif //CIRCULARTEMPLATEDLIST_PODCAST_H
