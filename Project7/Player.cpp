//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    
    // TODO: randomly roll the die and adjust the score for the current round accordingly
    //  increase the score if the amount matches this round's value
    int Player::roll( )
    {
        mDie.roll();
        int value = mDie.getValue();
        if (value == mRound) {
            mScore++;
        }
        return (value);
    }

    // TODO: allow for cheating
    // use the amount argument as this Player's roll
    // adjust the score for the current round accordingly
    // increase the score if the amount matches this round's value
    int Player::roll( int amount )
    {
        mDie.setValue(amount);
        if (amount == mRound) {
            mScore++;
        }
        return(amount);
    }
    
    // TODO: set the current round and reset the player's score to 0
    void Player::setRound( int round )
    {
        mRound = round;
        mScore = 0;
    }
    
    // TODO: return the score member variable
    int  Player::getScore( ) const
    {
        return(mScore);
    }
    
    int Player::getRound( ) const
    {
        return (mRound);
    }
}
