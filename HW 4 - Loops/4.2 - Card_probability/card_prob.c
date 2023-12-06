/**
 * This is a card shuffling probability calculator
 * It calculates the probability of being able to draw a card as part of a complex shuffling structure
 * It is made of the Main function as well as the
 */

#include <stdio.h>

double ProbabilityOfUndesiredCard(int UndesiredCards, int TotalCards, int CardsDrawn){
    /**
     * This function is used to calculate the probability any any stage of the shuffle
     * @param numUndesiredCards is used to store the number of number of undesired cards remaining in the shuffle
     * @param TotalCards and @param CardsDrawn play similar roles where they are used as placeholders
     * This prevents the values that are input into the function from being decreased.
     * The function returns the probability to the CalculateProbability function.
     */
    double numUndesiredCards = UndesiredCards;
    double numTotalCards = TotalCards;
    double probNotDesired = 1;
    for (int i = 0; i < CardsDrawn; ++i){
        probNotDesired *= numUndesiredCards/numTotalCards;
        numUndesiredCards --;
        numTotalCards --;
    }
    return probNotDesired;
}

double CalculateDesiredCardProbability(double CombinedProbabilities){
    /**
     * This is a simple function that was used to increase the total number of function in the program
     * It returns the final probability of picking the desired cards from the deck after the shuffles
     */
    return 1 - CombinedProbabilities;
}

double CalculateProbability( int inDeck, int handsCards, int desiredCards, int mulliganedCards, int turnsToDraw){
    /**
     * This function is used to calculate the probability of getting the desired cards
     * @param inDeck is used to store the total number of cards in the deck from user input
     * @param handsCards is used to store the total number of desiredCards or copies of cards in the deck from
     * user input.
     * @param handsCards is used to store the number of cards drawn initially from user input.
     * @param mulliganedCards is used to store the number of cards that are to be mulliganed from user input.
     * @param turnsToDraw is used to store the number of turns to draw the cards by after the mulligan is complete.
     * This value is also obtained from user input.
     * This function calls ProbNotDesiredCard to calculate each of the probabilities when the desired card is not
     * picked and multiply them.
     * Subsequently it called the function CalculateDesiredCardProbability to calculate the probability of drawing the
     * desired cards during the shuffles.
     * It returns the value of drawing the desired cards from the deck
     */

    double probNotDesiredCard;

    probNotDesiredCard = ProbabilityOfUndesiredCard(inDeck - desiredCards, inDeck,handsCards);

    probNotDesiredCard *= ProbabilityOfUndesiredCard(inDeck-desiredCards-handsCards,inDeck-handsCards, mulliganedCards);

    probNotDesiredCard *= ProbabilityOfUndesiredCard(inDeck-desiredCards-handsCards,inDeck-handsCards, turnsToDraw);

    probNotDesiredCard = CalculateDesiredCardProbability(probNotDesiredCard);

    return probNotDesiredCard;
}

int main(void){
    int cardsInDeck;
    int copiesOfTargetCard;
    int cardsInHand;
    int cardsMulliganing;
    int numTurnsToDrawBy;
    double probability;

    /**
     * The above variables except for probability are used to obtain user inputs
     * @double: probability is used to calculate the probability of drawing a desired card from the deck.
     */

    printf("Enter how many total cards there are in the deck: ");
    scanf(" %d", &cardsInDeck);

    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf(" %d", &copiesOfTargetCard);

    printf("Enter your initial hand size: ");
    scanf(" %d", &cardsInHand);

    printf("Enter how many cards you are mulliganing: ");
    scanf(" %d", &cardsMulliganing);

    printf("Enter what turn you want to draw the card by: ");
    scanf(" %d", &numTurnsToDrawBy);

    probability = CalculateProbability(cardsInDeck, cardsInHand, copiesOfTargetCard, cardsMulliganing, numTurnsToDrawBy);

    /**
     * The Calculate Probability function as described in the documentation does most of the heavy lifting and returns the value
     * of the probability of drawing the desired card.
     */

    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is"
           " %.2lf", numTurnsToDrawBy, cardsMulliganing, probability);

}

