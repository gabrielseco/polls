[%bs.raw {|require('./header.css')|}];

let component = ReasonReact.statelessComponent "Header";

let make ::title="Giphy" _children => {  
  {
    ...component,
    render: fun self =>
      <header className="header">
        <h3>(ReasonReact.stringToElement title)</h3>
      </header>
  }
};
