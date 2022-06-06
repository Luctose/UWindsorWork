function calcTotal(){
    let input = document.getElementById('myform');
    let sum = 0;
    for(i = 0; i < 12; ++i){
        input = document.getElementById('' + i);
        sum += parseInt(input.value);
    }
    document.getElementById('submit').innerHTML = 'Sub-Total $' + (sum * 4.35).toFixed(2) + ' <input type="submit"></input>';
}