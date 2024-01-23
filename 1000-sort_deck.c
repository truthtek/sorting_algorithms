#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

typedef struct Card {
    char suit[10];
    int value;
} Card;

typedef struct DeckNode {
    Card card;
    struct DeckNode* next;
} DeckNode;

int compare_cards(const void* a, const void* b) {
    const Card* card_a = (const Card*)a;
    const Card* card_b = (const Card*)b;

    // First, compare the suits
    int suit_cmp = strcmp(card_a->suit, card_b->suit);
    if (suit_cmp != 0) {
        return suit_cmp;
    }

    // If the suits are the same, compare the values
    return card_a->value - card_b->value;
}

void sort_deck(DeckNode** deck) {
    // Count the number of cards in the deck
    int card_count = 0;
    DeckNode* current = *deck;
    while (current != NULL) {
        card_count++;
        current = current->next;
    }

    // Create an array to hold the cards
    Card* cards = malloc(card_count * sizeof(Card));

    // Copy the cards from the deck into the array
    current = *deck;
    for (int i = 0; i < card_count; i++) {
        cards[i] = current->card;
        current = current->next;
    }

    // Sort the array of cards
    qsort(cards, card_count, sizeof(Card), compare_cards);

    // Reconstruct the deck with the sorted cards
    current = *deck;
    for (int i = 0; i < card_count; i++) {
        current->card = cards[i];
        current = current->next;
    }

    // Free the memory allocated for the array
    free(cards);
}

int main() {
    // Example usage:
    DeckNode* deck = malloc(sizeof(DeckNode));
    deck->card.value = 5;
    strcpy(deck->card.suit, "Spades");
    deck->next = malloc(sizeof(DeckNode));
    deck->next->card.value = 2;
    strcpy(deck->next->card.suit, "Diamonds");
    deck->next->next = malloc(sizeof(DeckNode));
    deck->next->next->card.value = 10;
    strcpy(deck->next->next->card.suit, "Hearts");
    deck->next->next->next = NULL;

    sort_deck(&deck);

    // Print the sorted deck
    DeckNode* current = deck;
    while (current != NULL) {
        printf("%s of %s\n", current->card.suit, current->card.value);
        current = current->next;
    }

    // Clean up the memory
    current = deck;
    while (current != NULL) {
        DeckNode* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
