[%bs.raw {|require('./app.css')|}];

let vDOM = Helpers.vDOM;

let component = ReasonReact.statelessComponent "App";

let make _children => {  
  {
    ...component,
    render: fun self =>
      <div className="root">
        <Header title="Polls"/>
        <div className="main">
          <h3>(vDOM "Welcome to Polls")</h3>
        </div>
        <Footer/>
      </div>
  }
};
