#include<iostream>
#include <ctype.h>
#include "Card.h"

using namespace std;


Card::Card()
{
    /* Assigns a default value of 2 of Clubs
*/
    rank = 2;
    suit = 'c';
}



Card::Card(char inputSuit, int inputRank)
{
    /* Assigns the Card the suit and rank provided.
   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
   If an invalid suit is provided, sets the suit to Clubs
   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
   If an invalid rank is provided, sets the rank to 2
   Accepts lower or upper case characters for suit
*/
    rank = inputRank;
    suit = inputSuit;
    if (!(rank > 0 && rank < 14))
    {
        rank = 2;
    }
    if (suit == 'C')
    {
        suit = 'c';
    }
    if (suit == 'H')
    {
        suit = 'h';
    }
    if (suit == 'D')
    {
        suit = 'd';
    }
    if (suit == 'S')
    {
        suit = 's';
    }

    if (!(suit == 'c' ||suit == 'h' || suit == 'd' || suit == 's'))
    {
        suit = 'c';
    }
}



char Card::getSuit() const
{
    /* Returns the Card's suit
*/
    return suit;
}



int Card::getRank() const
{
    /* Returns the Card's rank as an integer
*/
    return rank;
}


ostream& operator<<(ostream& out, const Card& hand)
{
    /* Outputs a Card in the following format: Rank of Suit
   For example, if the rank is 3 and the suit is h: 3 of Hearts
   Or, if the rank is 1 and the suit is d: Ace of Diamonds
   Or, if the rank is 12 and the suit is c: Queen of Clubs
   etc.
*/
    if (hand.suit == 'c')
    {
        if (hand.rank == 1)
        {
            out << "Ace of Clubs";
        }
        if (hand.rank > 1 && hand.rank < 11)
        {
            out << hand.rank << " of Clubs";
        }
        if (hand.rank == 11)
        {
            out << "Jack of Clubs";
        }
        if (hand.rank == 12)
        {
            out << "Queen of Clubs";
        }
        if (hand.rank == 13)
        {
            out << "King of Clubs";
        }
    }
    if (hand.suit == 'h')
    {
        if (hand.rank == 1)
        {
            out << "Ace of Hearts";
        }
        if (hand.rank > 1 && hand.rank < 11)
        {
            out << hand.rank << " of Hearts";
        }
        if (hand.rank == 11)
        {
            out << "Jack of Hearts";
        }
        if (hand.rank == 12)
        {
            out << "Queen of Hearts";
        }
        if (hand.rank == 13)
        {
            out << "King of Hearts";
        }
    }
    if (hand.suit == 'd')
    {
        if (hand.rank == 1)
        {
            out << "Ace of Diamonds";
        }
        if (hand.rank > 1 && hand.rank < 11)
        {
            out << hand.rank << " of Diamonds";
        }
        if (hand.rank == 11)
        {
            out << "Jack of Diamonds";
        }
        if (hand.rank == 12)
        {
            out << "Queen of Diamonds";
        }
        if (hand.rank == 13)
        {
            out << "King of Diamonds";
        }
    }
    if (hand.suit == 's')
    {
        if (hand.rank == 1)
        {
            out << "Ace of Spades";
        }
        if (hand.rank > 1 && hand.rank < 11)
        {
            out << hand.rank << " of Spades";
        }
        if (hand.rank == 11)
        {
            out << "Jack of Spades";
        }
        if (hand.rank == 12)
        {
            out << "Queen of Spades";
        }
        if (hand.rank == 13)
        {
            out << "King of Spades";
        }
    }
    return out;
}
