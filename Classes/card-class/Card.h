//
// Created by neald on 2/26/2025.
//

#ifndef CARD_H
#define CARD_H
#include <string>

enum class CardSuit {
    Spades,
    Clubs,
    Diamonds,
    Hearts
    // the enum's cases are secretly numbered starting from 0.
};

class Card {
    // By default, the members of a class are private -- they cannot be referred to
    // outside of this class.

    CardSuit m_suit {}; // by default, will be initialized to 0. (Spades)
    int m_kind {1}; // by default, will be initialized to 1. (Ace)

public:
    // CONSTUCTORS: how does someone create a Card?

    Card() = default;
    // Someone can create a card with no parameters, using just the default
    // field values.

    Card(CardSuit suit, int kind);
    // Someone can create a card with a specific suit and kind.


    // METHODS: what can we do with a Card?
    // Accessors: we can retrieve individual fields of a Card, if that might be
    // helpful for the public to know.
    CardSuit getSuit() const;
    int getKind() const;

    // Mutators: if we want to allow it, the public can change the values of our
    // fields, after we check that they are valid values.
    void setSuit(CardSuit suit);
    void setKind(int kind);

    // Other methods: what else can a Card do?
    std::string toString() const;
};


#endif //CARD_H
