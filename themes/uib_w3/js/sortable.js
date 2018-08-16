jQuery (document).ready(function ($) {
  $(".uib-table-wrapper>table.sortable>tbody>tr>th").click(function(){
  var table = $(this).parent().parent().parent();
  var rows = table.find('tr:gt(0)').toArray().sort(comparer($(this).index()))
    this.asc = !this.asc

    if (!this.asc){rows = rows.reverse()}
    for (var i = 0; i < rows.length; i++){table.append(rows[i])}
  });

  function comparer(index) {
    return function(a, b) {
      var valA = getCellValue(a, index), valB = getCellValue(b, index)
      return $.isNumeric(valA) && $.isNumeric(valB) ? valA - valB : valA.toString().localeCompare(valB)
    }
  }

  function getCellValue(row, index){
    return $(row).children('td').eq(index).text()
  }
});
