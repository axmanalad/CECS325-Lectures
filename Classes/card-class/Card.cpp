//
// Created by neald on 2/26/2025.
//

#include "Card.h"

#include <sstream>

Card::Card(CardSuit suit, int kind)
    : m_suit(suit), m_kind(kind)
{
}

CardSuit Card::getSuit() const {
    return m_suit;
}

int Card::getKind() const {
    return m_kind;
}

void Card::setSuit(CardSuit suit) {
    m_suit = suit;
}

void Card::setKind(int kind) {
    if (kind >= 1 && kind <= 13) {
        m_kind = kind;
    }
}

std::string Card::toString() const {
    std::ostringstream cardName;
    switch (m_kind) {
        case 1:
            cardName << "Ace";
        break;
        case 11:
            cardName << "Jack";
        break;
        case 12:
            cardName << "Queen";
        break;
        case 13:
            cardName << "King";
        break;
        default:
            cardName << m_kind;
        break;
    }

    cardName << " of ";
    switch (m_suit) {
        case CardSuit::Spades:
            cardName << "Spades";
        break;
        case CardSuit::Clubs:
            cardName << "Clubs";
        break;
        case CardSuit::Diamonds:
            cardName << "Diamonds";
        break;
        case CardSuit::Hearts:
            cardName << "Hearts";
        break;
    }
    return cardName.str();
}
