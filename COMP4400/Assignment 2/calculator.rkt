; Left associative

#lang scheme

(define(calculator exp)
  (cond
    ((null? exp) 0)
    ((null? (cdr exp)) (car exp))
    ((or (eqv? (car exp) '+) (eqv? (car exp) '-))
     (if(eqv? (car exp) '+)
                (+ (cadr exp) (calculator(cdr (cdr exp))))
           (- (calculator(cdr (cdr exp))) (cadr exp))))
    (else (+ (car exp) (calculator(cdr exp)))
          )))

(calculator'(12 - 3 + 1 + 6 - 45 + 12 + 55))